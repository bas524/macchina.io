//
// UserSerializer.h
//
// Package: Generated
// Module:  TypeSerializer
//
// This file has been generated.
// Warning: All changes to this will be lost when the file is re-generated.
//
// Copyright (c) 2017, IVK CJSC.
// All rights reserved.
// 
//


#ifndef TypeSerializer_IoT_PasswdService_User_INCLUDED
#define TypeSerializer_IoT_PasswdService_User_INCLUDED


#include "IoT/Passwd/GroupDeserializer.h"
#include "IoT/Passwd/GroupSerializer.h"
#include "IoT/Passwd/PasswdService.h"
#include "IoT/Passwd/UserDeserializer.h"
#include "IoT/Passwd/UserSerializer.h"
#include "Poco/RemotingNG/TypeSerializer.h"


namespace Poco {
namespace RemotingNG {


template <>
class TypeSerializer<IoT::PasswdService::User>
{
public:
	static void serialize(const std::string& name, const IoT::PasswdService::User& value, Serializer& ser)
	{
		ser.serializeStructBegin(name);
		serializeImpl(value, ser);
		ser.serializeStructEnd(name);
	}

	static void serializeImpl(const IoT::PasswdService::User& value, Serializer& ser)
	{
		remoting__staticInitBegin(REMOTING__NAMES);
		static const std::string REMOTING__NAMES[] = {"gid","groups","id","name","nic","passwordHash",""};
		remoting__staticInitEnd(REMOTING__NAMES);
		TypeSerializer<size_t >::serialize(REMOTING__NAMES[0], value.gid, ser);
		TypeSerializer<std::vector < IoT::PasswdService::Group > >::serialize(REMOTING__NAMES[1], value.groups, ser);
		TypeSerializer<size_t >::serialize(REMOTING__NAMES[2], value.id, ser);
		TypeSerializer<std::string >::serialize(REMOTING__NAMES[3], value.name, ser);
		TypeSerializer<std::string >::serialize(REMOTING__NAMES[4], value.nic, ser);
		TypeSerializer<std::string >::serialize(REMOTING__NAMES[5], value.passwordHash, ser);
	}

};


} // namespace RemotingNG
} // namespace Poco


#endif // TypeSerializer_IoT_PasswdService_User_INCLUDED

