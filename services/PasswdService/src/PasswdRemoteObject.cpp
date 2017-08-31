//
// PasswdRemoteObject.cpp
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


#include "IoT/Passwd/PasswdRemoteObject.h"


namespace IoT {
namespace PasswdService {


PasswdRemoteObject::PasswdRemoteObject(const Poco::RemotingNG::Identifiable::ObjectId& oid, Poco::SharedPtr<IoT::PasswdService::Passwd> pServiceObject):
	IoT::PasswdService::IPasswd(),
	Poco::RemotingNG::RemoteObject(oid),
	_pServiceObject(pServiceObject)
{
}


PasswdRemoteObject::~PasswdRemoteObject()
{
	try
	{
	}
	catch (...)
	{
		poco_unexpected();
	}
}


} // namespace PasswdService
} // namespace IoT

