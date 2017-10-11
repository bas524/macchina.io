//
// GroupDeserializer.h
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


#ifndef TypeDeserializer_IoT_PasswdService_Group_INCLUDED
#define TypeDeserializer_IoT_PasswdService_Group_INCLUDED


#include "IoT/Passwd/PasswdService.h"
#include "Poco/RemotingNG/TypeDeserializer.h"


namespace Poco {
namespace RemotingNG {


template <>
class TypeDeserializer<IoT::PasswdService::Group>
{
public:
	static bool deserialize(const std::string& name, bool isMandatory, Deserializer& deser, IoT::PasswdService::Group& value)
	{
		bool ret = deser.deserializeStructBegin(name, isMandatory);
		if (ret)
		{
			deserializeImpl(deser, value);
			deser.deserializeStructEnd(name);
		}
		return ret;
	}

	static void deserializeImpl(Deserializer& deser, IoT::PasswdService::Group& value)
	{
		remoting__staticInitBegin(REMOTING__NAMES);
		static const std::string REMOTING__NAMES[] = {"id","name"};
		remoting__staticInitEnd(REMOTING__NAMES);
		TypeDeserializer<unsigned long >::deserialize(REMOTING__NAMES[0], false, deser, value.id);
		TypeDeserializer<std::string >::deserialize(REMOTING__NAMES[1], false, deser, value.name);
	}

};


} // namespace RemotingNG
} // namespace Poco


#endif // TypeDeserializer_IoT_PasswdService_Group_INCLUDED

