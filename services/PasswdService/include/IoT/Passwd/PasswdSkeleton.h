//
// PasswdSkeleton.h
//
// Library: IoT/Passwd
// Package: Generated
// Module:  PasswdSkeleton
//
// This file has been generated.
// Warning: All changes to this will be lost when the file is re-generated.
//
// Copyright (c) 2017, IVK CJSC.
// All rights reserved.
// 
//


#ifndef IoT_Passwd_PasswdSkeleton_INCLUDED
#define IoT_Passwd_PasswdSkeleton_INCLUDED


#include "IoT/Passwd/PasswdRemoteObject.h"
#include "Poco/RemotingNG/Skeleton.h"


namespace IoT {
namespace PasswdService {


class PasswdSkeleton: public Poco::RemotingNG::Skeleton
{
public:
	PasswdSkeleton();
		/// Creates a PasswdSkeleton.

	virtual ~PasswdSkeleton();
		/// Destroys a PasswdSkeleton.

	virtual const Poco::RemotingNG::Identifiable::TypeId& remoting__typeId() const;

	static const std::string DEFAULT_NS;
};


inline const Poco::RemotingNG::Identifiable::TypeId& PasswdSkeleton::remoting__typeId() const
{
	return IPasswd::remoting__typeId();
}


} // namespace PasswdService
} // namespace IoT


#endif // IoT_Passwd_PasswdSkeleton_INCLUDED

