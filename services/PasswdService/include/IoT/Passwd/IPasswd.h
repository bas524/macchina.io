//
// IPasswd.h
//
// Library: IoT/Passwd
// Package: Generated
// Module:  IPasswd
//
// This file has been generated.
// Warning: All changes to this will be lost when the file is re-generated.
//
// Copyright (c) 2017, IVK CJSC.
// All rights reserved.
// 
//


#ifndef IoT_Passwd_IPasswd_INCLUDED
#define IoT_Passwd_IPasswd_INCLUDED


#include "IoT/Passwd/PasswdService.h"
#include "Poco/AutoPtr.h"
#include "Poco/OSP/Service.h"
#include "Poco/RemotingNG/Identifiable.h"


namespace IoT {
namespace PasswdService {


class IPasswd: public Poco::OSP::Service
{
public:
	typedef Poco::AutoPtr<IPasswd> Ptr;

	IPasswd();
		/// Creates a IPasswd.

	virtual ~IPasswd();
		/// Destroys the IPasswd.

	virtual IoT::PasswdService::User byNic(const std::string& nic) const = 0;

	virtual IoT::PasswdService::User currentUser() const = 0;

	virtual std::vector < IoT::PasswdService::Group > groups() const = 0;

	bool isA(const std::type_info& otherType) const;
		/// Returns true if the class is a subclass of the class given by otherType.

	static const Poco::RemotingNG::Identifiable::TypeId& remoting__typeId();
		/// Returns the TypeId of the class.

	const std::type_info& type() const;
		/// Returns the type information for the object's class.

	virtual std::vector < IoT::PasswdService::Group > userGroups(const IoT::PasswdService::User& user) const = 0;

	virtual std::vector < IoT::PasswdService::User > users() const = 0;

};


} // namespace PasswdService
} // namespace IoT


#endif // IoT_Passwd_IPasswd_INCLUDED

