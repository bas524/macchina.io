//
// PasswdRemoteObject.h
//
// Library: IoT/Passwd
// Package: Generated
// Module:  PasswdRemoteObject
//
// This file has been generated.
// Warning: All changes to this will be lost when the file is re-generated.
//
// Copyright (c) 2017, IVK CJSC.
// All rights reserved.
// 
//


#ifndef IoT_Passwd_PasswdRemoteObject_INCLUDED
#define IoT_Passwd_PasswdRemoteObject_INCLUDED


#include "IoT/Passwd/IPasswd.h"
#include "Poco/RemotingNG/Identifiable.h"
#include "Poco/RemotingNG/RemoteObject.h"
#include "Poco/SharedPtr.h"


namespace IoT {
namespace PasswdService {


class PasswdRemoteObject: public IoT::PasswdService::IPasswd, public Poco::RemotingNG::RemoteObject
{
public:
	typedef Poco::AutoPtr<PasswdRemoteObject> Ptr;

	PasswdRemoteObject(const Poco::RemotingNG::Identifiable::ObjectId& oid, Poco::SharedPtr<IoT::PasswdService::Passwd> pServiceObject);
		/// Creates a PasswdRemoteObject.

	virtual ~PasswdRemoteObject();
		/// Destroys the PasswdRemoteObject.

	virtual bool authenticate(const std::string& userName, const std::string& password) const;

	virtual bool authorize(const std::string& userName, const std::string& permission) const;

	IoT::PasswdService::User byNic(const std::string& nic) const;

	IoT::PasswdService::User currentUser() const;

	std::vector < IoT::PasswdService::Group > groups() const;

	virtual const Poco::RemotingNG::Identifiable::TypeId& remoting__typeId() const;

	std::vector < IoT::PasswdService::Group > userGroups(const IoT::PasswdService::User& user) const;

	std::vector < IoT::PasswdService::User > users() const;

private:
	Poco::SharedPtr<IoT::PasswdService::Passwd> _pServiceObject;
};


inline bool PasswdRemoteObject::authenticate(const std::string& userName, const std::string& password) const
{
	return _pServiceObject->authenticate(userName, password);
}


inline bool PasswdRemoteObject::authorize(const std::string& userName, const std::string& permission) const
{
	return _pServiceObject->authorize(userName, permission);
}


inline IoT::PasswdService::User PasswdRemoteObject::byNic(const std::string& nic) const
{
	return _pServiceObject->byNic(nic);
}


inline IoT::PasswdService::User PasswdRemoteObject::currentUser() const
{
	return _pServiceObject->currentUser();
}


inline std::vector < IoT::PasswdService::Group > PasswdRemoteObject::groups() const
{
	return _pServiceObject->groups();
}


inline const Poco::RemotingNG::Identifiable::TypeId& PasswdRemoteObject::remoting__typeId() const
{
	return IPasswd::remoting__typeId();
}


inline std::vector < IoT::PasswdService::Group > PasswdRemoteObject::userGroups(const IoT::PasswdService::User& user) const
{
	return _pServiceObject->userGroups(user);
}


inline std::vector < IoT::PasswdService::User > PasswdRemoteObject::users() const
{
	return _pServiceObject->users();
}


} // namespace PasswdService
} // namespace IoT


#endif // IoT_Passwd_PasswdRemoteObject_INCLUDED

