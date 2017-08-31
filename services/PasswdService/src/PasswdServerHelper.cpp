//
// PasswdServerHelper.cpp
//
// Library: IoT/Passwd
// Package: Generated
// Module:  PasswdServerHelper
//
// This file has been generated.
// Warning: All changes to this will be lost when the file is re-generated.
//
// Copyright (c) 2017, IVK CJSC.
// All rights reserved.
// 
//


#include "IoT/Passwd/PasswdServerHelper.h"
#include "IoT/Passwd/PasswdSkeleton.h"
#include "Poco/RemotingNG/URIUtility.h"
#include "Poco/SingletonHolder.h"


namespace IoT {
namespace PasswdService {


namespace
{
	static Poco::SingletonHolder<PasswdServerHelper> shPasswdServerHelper;
}


PasswdServerHelper::PasswdServerHelper():
	_pORB(0)
{
	_pORB = &Poco::RemotingNG::ORB::instance();
	registerSkeleton();
}


PasswdServerHelper::~PasswdServerHelper()
{
}


void PasswdServerHelper::shutdown()
{
	PasswdServerHelper::instance().unregisterSkeleton();
	shPasswdServerHelper.reset();
}


Poco::AutoPtr<IoT::PasswdService::PasswdRemoteObject> PasswdServerHelper::createRemoteObjectImpl(Poco::SharedPtr<IoT::PasswdService::Passwd> pServiceObject, const Poco::RemotingNG::Identifiable::ObjectId& oid)
{
	return new PasswdRemoteObject(oid, pServiceObject);
}


PasswdServerHelper& PasswdServerHelper::instance()
{
	return *shPasswdServerHelper.get();
}


std::string PasswdServerHelper::registerObjectImpl(Poco::AutoPtr<IoT::PasswdService::PasswdRemoteObject> pRemoteObject, const std::string& listenerId)
{
	return _pORB->registerObject(pRemoteObject, listenerId);
}


void PasswdServerHelper::registerSkeleton()
{
	_pORB->registerSkeleton("IoT.PasswdService.Passwd", new PasswdSkeleton);
}


void PasswdServerHelper::unregisterObjectImpl(const std::string& uri)
{
	_pORB->unregisterObject(uri);
}


void PasswdServerHelper::unregisterSkeleton()
{
	_pORB->unregisterSkeleton("IoT.PasswdService.Passwd", true);
}


} // namespace PasswdService
} // namespace IoT

