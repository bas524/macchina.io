//
// PasswdServiceImpl.h
//
// $Id$
//
// Library: IoT/PasswdService
// Package: PasswdServiceImpl
// Module:  PasswdServiceImpl
//
// Definition of the PasswdServiceImpl class.
//
// Copyright (c) 2017, IVK CJSC.
// All rights reserved.
//


#ifndef IoT_PasswdServiceImpl_INCLUDED
#define IoT_PasswdServiceImpl_INCLUDED

#include "IoT/Passwd/PasswdService.h"
#include "Poco/OSP/BundleContext.h"
#include "Poco/Data/Session.h"
#include "Poco/ActiveMethod.h"
#include "Poco/ActiveDispatcher.h"
#include "Poco/Clock.h"
#include "Poco/SharedPtr.h"
#include "Poco/Logger.h"
#include "Poco/Mutex.h"

struct passwd;
struct group;

namespace IoT
{
namespace PasswdService
{
class PasswdServiceImpl : public Passwd
/// Default implementation of the Passwd.
{
	mutable struct passwd *_pw;
	mutable struct group *_gr;
	struct UserUtil
	{
		static bool isValid(const User &user)
		{
			return !user.nic.empty() && !user.groups.empty();
		}
		static bool hasGroup(const User &user, const GroupName &groupName)
		{
			for(Groups::const_iterator it = user.groups.begin(); it != user.groups.end(); ++it)
			{
				if(it->name == groupName)
				{
					return true;
				}
			}
			return false;
		}
	};
public:
	PasswdServiceImpl(Poco::OSP::BundleContext::Ptr pContext);
	/// Creates the PasswdServiceImpl.
	virtual ~PasswdServiceImpl();
	/// Destroys the PasswdService.
	Groups groups() const;
	Groups userGroups(const User &user) const;
	Users users() const;
	User currentUser() const;
	User byNic(const UserNic &nic) const;
	bool authenticate(const std::string &userName, const std::string &password) const;
	bool authorize(const std::string &userName, const std::string &permission) const;
protected:
	unsigned long UID_MIN() const;
private:
	void resetGroups() const;
	void resetUsers() const;
	Groups groups(const std::string &nic, unsigned long gid) const;
private:
	Poco::OSP::BundleContext::Ptr _pContext;
	Poco::Logger &_logger;
};

}
} // namespace IoT::PasswdService


#endif // IoT_PasswdServiceImpl_INCLUDED
