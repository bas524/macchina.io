//
// IPasswd.cpp
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


#include "IoT/Passwd/IPasswd.h"


namespace IoT {
namespace PasswdService {


IPasswd::IPasswd():
	Poco::OSP::Service()

{
}


IPasswd::~IPasswd()
{
}


bool IPasswd::isA(const std::type_info& otherType) const
{
	std::string name(type().name());
	return name == otherType.name();
}


const Poco::RemotingNG::Identifiable::TypeId& IPasswd::remoting__typeId()
{
	remoting__staticInitBegin(REMOTING__TYPE_ID);
	static const std::string REMOTING__TYPE_ID("IoT.PasswdService.Passwd");
	remoting__staticInitEnd(REMOTING__TYPE_ID);
	return REMOTING__TYPE_ID;
}


const std::type_info& IPasswd::type() const
{
	return typeid(IPasswd);
}


} // namespace PasswdService
} // namespace IoT

