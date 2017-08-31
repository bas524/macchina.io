//
// GroupSerializer.h
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


#ifndef TypeSerializer_IoT_PasswdService_Group_INCLUDED
#define TypeSerializer_IoT_PasswdService_Group_INCLUDED


#include "IoT/Passwd/PasswdService.h"
#include "IoT/Passwd/GroupDeserializer.h"
#include "IoT/Passwd/GroupSerializer.h"
#include "Poco/RemotingNG/TypeSerializer.h"


namespace Poco {
namespace RemotingNG {


template <>
class TypeSerializer<IoT::PasswdService::Group>
{
public:
	static void serialize(const std::string& name, const IoT::PasswdService::Group& value, Serializer& ser)
	{
		ser.serializeStructBegin(name);
		serializeImpl(value, ser);
		ser.serializeStructEnd(name);
	}

	static void serializeImpl(const IoT::PasswdService::Group& value, Serializer& ser)
	{
		remoting__staticInitBegin(REMOTING__NAMES);
		static const std::string REMOTING__NAMES[] = {"id","name",""};
		remoting__staticInitEnd(REMOTING__NAMES);
		TypeSerializer<size_t >::serialize(REMOTING__NAMES[0], value.id, ser);
		TypeSerializer<std::string >::serialize(REMOTING__NAMES[1], value.name, ser);
	}

};


} // namespace RemotingNG
} // namespace Poco


#endif // TypeSerializer_IoT_PasswdService_Group_INCLUDED

