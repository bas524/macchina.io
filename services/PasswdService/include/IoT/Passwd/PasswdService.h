//
// PasswdService.h
//
// $Id$
//
// Library: IoT/Passwd
// Package: PasswdService
// Module:  PasswdService
//
// Definition of the PasswdService interface.
//
// Copyright (c) 2017, IVK CJSC.
// All rights reserved.
//
//


#ifndef IoT_PasswdService_INCLUDED
#define IoT_PasswdService_INCLUDED

#include "IoT/Passwd/Passwd.h"
#include "Poco/BasicEvent.h"
#include "Poco/DateTime.h"
#include "Poco/Optional.h"
#include "Poco/SharedPtr.h"

namespace IoT
{
namespace PasswdService
{

typedef size_t GroupID;
typedef std::string GroupName;

//@ serialize
struct Group
{
	Group(GroupID _id_, const GroupName &_name_) : id(_id_), name(_name_) { }
	Group() { };
	//@ mandatory=false
	GroupID id;
	//@ mandatory=false
	GroupName name;
};
typedef std::vector<Group> Groups;

typedef size_t UserID;
typedef size_t UserGID;
typedef std::string UserNic;
typedef std::string UserName;
typedef std::string UserPasswordHash;

//@ serialize	
struct User
{
	User(UserID _id_, UserGID _gid_, const UserNic &_nic_, const UserName &_name_, const UserPasswordHash &_passwordHash_, const Groups &_groups_)
	: id(_id_), gid(_gid_), nic(_nic_), name(_name_), passwordHash(_passwordHash_), groups(_groups_) { }
	User() {};
	//@ mandatory=false
	UserID id;
	//@ mandatory=false
	UserGID gid;
	//@ mandatory=false
	UserNic nic;
	//@ mandatory=false
	UserName name;
	//@ mandatory=false
	UserPasswordHash passwordHash;
	//@ mandatory=false
	Groups groups;
};
typedef std::vector<User> Users;

//@ remote
class Passwd
{
public:
    typedef Poco::SharedPtr<Passwd> Ptr;
	Passwd();
	virtual Groups groups() const = 0;
	virtual Groups userGroups(const User &user) const = 0;
	virtual Users users() const = 0;
	virtual User currentUser() const = 0;
	virtual User byNic(const UserNic &nic) const = 0;
	virtual bool authenticate(const std::string &userName, const std::string &password) const = 0;
	virtual bool authorize(const std::string &userName, const std::string &permission) const = 0;
	virtual ~Passwd();
protected:
	virtual size_t UID_MIN() const = 0;
};

}
} // namespace IoT::PasswdService


#endif // IoT_PasswdService_INCLUDED
