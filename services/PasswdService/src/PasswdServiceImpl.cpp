//
// PasswdServiceImpl.cpp
//
// $Id$
//
// Library: IoT/Passwd
// Package: PasswdServiceImpl
// Module:  PasswdServiceImpl
//
// Copyright (c) 2017, IVK CJSC.
// All rights reserved.
//

#include "PasswdServiceImpl.h"
#include <grp.h>
#include <pwd.h>
#include <security/pam_appl.h>
#include <security/pam_misc.h>
#include <shadow.h>
#include <unistd.h>
#include <cstring>
#include <stdexcept>
#include "Poco/Data/Statement.h"
#include "Poco/Data/Transaction.h"
#include "Poco/Path.h"
#include "Poco/Timespan.h"

namespace IoT {
namespace PasswdService {

PasswdServiceImpl::PasswdServiceImpl(Poco::OSP::BundleContext::Ptr pContext)
: _pw(NULL),
_gr(NULL),
_pContext(pContext),
_logger(Poco::Logger::get("IoT.PasswdService")) {
  setpwent();
  _pw = getpwent();

  setgrent();
  _gr = getgrent();
}

PasswdServiceImpl::~PasswdServiceImpl() {
  endpwent();
  endgrent();
}

Groups PasswdServiceImpl::groups() const {
  if (_gr == NULL) {
    return PasswdService::Groups();
  }
  PasswdService::Groups groups;
  setgrent();
  do {
    groups.push_back(Group(static_cast<PasswdService::GroupID> (_gr->gr_gid),
        std::string(_gr->gr_name)));
    _gr = getgrent();
  } while (_gr != NULL);

  resetGroups();

  return groups;
}

Groups PasswdServiceImpl::userGroups(const User &user) const {
  return groups(user.nic, user.gid);
}

Users PasswdServiceImpl::users() const {
  if (_pw == NULL) {
    return PasswdService::Users();
  }

  Users users;
  size_t uid_min = UID_MIN();
  do {
    if (_pw->pw_uid > uid_min || _pw->pw_uid == 0) {
      User user(_pw->pw_uid, _pw->pw_gid, _pw->pw_name, _pw->pw_gecos,
          _pw->pw_passwd, groups(_pw->pw_name, _pw->pw_gid));
      users.push_back(user);
    }
    _pw = getpwent();
  } while (_pw != NULL);
  resetUsers();

  return users;
}

User PasswdServiceImpl::currentUser() const {
  struct passwd *pw = getpwuid(getuid());
  if (pw == NULL) {
    return PasswdService::User();
  }
  return User(pw->pw_uid, pw->pw_gid, pw->pw_name, pw->pw_gecos, pw->pw_passwd,
      groups(pw->pw_name, pw->pw_gid));
}

User PasswdServiceImpl::byNic(const UserNic &nic) const {
  Users users = this->users();
  for (Users::const_iterator it = users.begin(); it != users.end(); ++it) {
    if (it->nic == nic) {
      return *it;
    }
  }
  return User();
}
typedef int (*conv_t)(int num_msg, const struct pam_message **msg,
    struct pam_response **resp, void *appdata_ptr);

struct FunctionConversation {

  explicit FunctionConversation(const std::string &password)
  : f(reinterpret_cast<conv_t> (&FunctionConversation::conv)),
  _password(password) {
  }

  int conv(int num_msg, const struct pam_message **msg,
      struct pam_response **resp, void *appdata_ptr) {
    if (resp) {
      _reply =
          (struct pam_response *) calloc(num_msg, sizeof (struct pam_response));
      if (_reply == NULL) {
        return PAM_CONV_ERR;
      }

      _reply->resp = strdup(const_cast<char *> (_password.c_str()));
      _reply->resp_retcode = 0;

      *resp = _reply;
    }
    return PAM_SUCCESS;
  }
  conv_t f = NULL;

private:
  std::string _password;

  struct pam_response *_reply;
};

bool PasswdServiceImpl::authenticate(const std::string &userName, const std::string &password) const {
  bool result = true;

  FunctionConversation functionConversation(password);

  const struct pam_conv local_conversation = {functionConversation.f, NULL};
  pam_handle_t *local_auth_handle = NULL; // this gets set by pam_start

  int retval = pam_start("macchina", userName.c_str(), &local_conversation,
      &local_auth_handle);
  if (retval != PAM_SUCCESS) {
    return false;
  }

  retval = pam_authenticate(local_auth_handle, 0);
  if (retval != PAM_SUCCESS) {
    result = false;
  } else {
    retval = pam_acct_mgmt(local_auth_handle, 0);
    if (retval != PAM_SUCCESS) {
      result = false;
    }
  }

  retval = pam_end(local_auth_handle, retval);
  return result;
}

bool PasswdServiceImpl::authorize(const std::string &userName, const std::string &permission) const {
  User user = byNic(userName);
  return (UserUtil::isValid(user) && UserUtil::hasGroup(user, permission));
}

size_t PasswdServiceImpl::UID_MIN() const {
  User user = currentUser();
  size_t uid = user.id;

  if (uid == 0) {
    return 500;
  }

  size_t uid_min = uid / 100;
  if (uid_min < 10) {
    return uid_min * 100;
  }
  if (uid_min >= 10) {
    return (uid / 1000) * 1000;
  }
  return 1000;
}

void PasswdServiceImpl::resetGroups() const {
  setgrent();
  _gr = getgrent();
}

void PasswdServiceImpl::resetUsers() const {
  setpwent();
  _pw = getpwent();
}

Groups PasswdServiceImpl::groups(const std::string &nic, size_t gid) const {
  int ngroups = 1024;
  std::vector<gid_t> cgroups;
  struct group *gr = NULL;
  cgroups.reserve(static_cast<size_t> (ngroups));

  Groups groups;

  if (getgrouplist(nic.c_str(), static_cast<gid_t> (gid), &cgroups[0],
      &ngroups) != -1) {
    for (int j = 0; j < ngroups; j++) {
      gr = getgrgid(cgroups[j]);
      if (gr != NULL) {
        groups.push_back(Group(gr->gr_gid, std::string(gr->gr_name)));
      }
    }
  }

  return groups;
}
} // namespace PasswdService
} // namespace IoT
