//
// UserDeserializer.h
//
// Package: Generated
// Module:  TypeDeserializer
//
// This file has been generated.
// Warning: All changes to this will be lost when the file is re-generated.
//
// Copyright (c) 2017, IVK CJSC.
// All rights reserved.
// 
//


#ifndef TypeDeserializer_IoT_PasswdService_User_INCLUDED
#define TypeDeserializer_IoT_PasswdService_User_INCLUDED


#include "IoT/Passwd/GroupDeserializer.h"
#include "IoT/Passwd/GroupSerializer.h"
#include "IoT/Passwd/PasswdService.h"
#include "IoT/Passwd/UserDeserializer.h"
#include "IoT/Passwd/UserSerializer.h"
#include "Poco/RemotingNG/TypeDeserializer.h"


namespace Poco {
namespace RemotingNG {


template <>
class TypeDeserializer<IoT::PasswdService::User>
{
public:
	static bool deserialize(const std::string& name, bool isMandatory, Deserializer& deser, IoT::PasswdService::User& value)
	{
		bool ret = deser.deserializeStructBegin(name, isMandatory);
		if (ret)
		{
			deserializeImpl(deser, value);
			deser.deserializeStructEnd(name);
		}
		return ret;
	}

	static void deserializeImpl(Deserializer& deser, IoT::PasswdService::User& value)
	{
		remoting__staticInitBegin(REMOTING__NAMES);
		static const std::string REMOTING__NAMES[] = {"gid","groups","id","name","nic","passwordHash"};
		remoting__staticInitEnd(REMOTING__NAMES);
		TypeDeserializer<size_t >::deserialize(REMOTING__NAMES[0], false, deser, value.gid);
		TypeDeserializer<std::vector < IoT::PasswdService::Group > >::deserialize(REMOTING__NAMES[1], false, deser, value.groups);
		TypeDeserializer<size_t >::deserialize(REMOTING__NAMES[2], false, deser, value.id);
		TypeDeserializer<std::string >::deserialize(REMOTING__NAMES[3], false, deser, value.name);
		TypeDeserializer<std::string >::deserialize(REMOTING__NAMES[4], false, deser, value.nic);
		TypeDeserializer<std::string >::deserialize(REMOTING__NAMES[5], false, deser, value.passwordHash);
	}

};


} // namespace RemotingNG
} // namespace Poco


#endif // TypeDeserializer_IoT_PasswdService_User_INCLUDED

