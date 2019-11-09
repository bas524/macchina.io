//
// IUnitsOfMeasureService.cpp
//
// Library: IoT/UnitsOfMeasure
// Package: Generated
// Module:  IUnitsOfMeasureService
//
// This file has been generated.
// Warning: All changes to this will be lost when the file is re-generated.
//
// Copyright (c) 2018, Applied Informatics Software Engineering GmbH.
// All rights reserved.
// 
// SPDX-License-Identifier: Apache-2.0
//


#include "IoT/UnitsOfMeasure/IUnitsOfMeasureService.h"


namespace IoT {
namespace UnitsOfMeasure {


IUnitsOfMeasureService::IUnitsOfMeasureService():
	Poco::OSP::Service()

{
}


IUnitsOfMeasureService::~IUnitsOfMeasureService()
{
}


bool IUnitsOfMeasureService::isA(const std::type_info& otherType) const
{
	std::string name(type().name());
	return name == otherType.name();
}


const Poco::RemotingNG::Identifiable::TypeId& IUnitsOfMeasureService::remoting__typeId()
{
	remoting__staticInitBegin(REMOTING__TYPE_ID);
	static const std::string REMOTING__TYPE_ID("IoT.UnitsOfMeasure.UnitsOfMeasureService");
	remoting__staticInitEnd(REMOTING__TYPE_ID);
	return REMOTING__TYPE_ID;
}


const std::type_info& IUnitsOfMeasureService::type() const
{
	return typeid(IUnitsOfMeasureService);
}


} // namespace UnitsOfMeasure
} // namespace IoT

