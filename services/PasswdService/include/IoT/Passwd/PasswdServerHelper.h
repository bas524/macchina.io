//
// PasswdServerHelper.h
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


#ifndef IoT_Passwd_PasswdServerHelper_INCLUDED
#define IoT_Passwd_PasswdServerHelper_INCLUDED


#include "IoT/Passwd/IPasswd.h"
#include "IoT/Passwd/PasswdRemoteObject.h"
#include "IoT/Passwd/PasswdService.h"
#include "Poco/RemotingNG/Identifiable.h"
#include "Poco/RemotingNG/ORB.h"
#include "Poco/RemotingNG/ServerHelper.h"


namespace IoT {
namespace PasswdService {


class PasswdServerHelper
{
public:
	typedef IoT::PasswdService::Passwd Service;

	PasswdServerHelper();
		/// Creates a PasswdServerHelper.

	~PasswdServerHelper();
		/// Destroys the PasswdServerHelper.

	static Poco::AutoPtr<IoT::PasswdService::PasswdRemoteObject> createRemoteObject(Poco::SharedPtr<IoT::PasswdService::Passwd> pServiceObject, const Poco::RemotingNG::Identifiable::ObjectId& oid);
		/// Creates and returns a RemoteObject wrapper for the given IoT::PasswdService::Passwd instance.

	static std::string registerObject(Poco::SharedPtr<IoT::PasswdService::Passwd> pServiceObject, const Poco::RemotingNG::Identifiable::ObjectId& oid, const std::string& listenerId);
		/// Creates a RemoteObject wrapper for the given IoT::PasswdService::Passwd instance
		/// and registers it with the ORB and the Listener instance
		/// uniquely identified by the Listener's ID.
		/// 
		///	Returns the URI created for the object.

	static std::string registerRemoteObject(Poco::AutoPtr<IoT::PasswdService::PasswdRemoteObject> pRemoteObject, const std::string& listenerId);
		/// Registers the given RemoteObject with the ORB and the Listener instance
		/// uniquely identified by the Listener's ID.
		/// 
		///	Returns the URI created for the object.

	static void shutdown();
		/// Removes the Skeleton for IoT::PasswdService::Passwd from the ORB.

	static void unregisterObject(const std::string& uri);
		/// Unregisters a service object identified by URI from the ORB.

private:
	static Poco::AutoPtr<IoT::PasswdService::PasswdRemoteObject> createRemoteObjectImpl(Poco::SharedPtr<IoT::PasswdService::Passwd> pServiceObject, const Poco::RemotingNG::Identifiable::ObjectId& oid);

	static PasswdServerHelper& instance();
		/// Returns a static instance of the helper class.

	std::string registerObjectImpl(Poco::AutoPtr<IoT::PasswdService::PasswdRemoteObject> pRemoteObject, const std::string& listenerId);

	void registerSkeleton();

	void unregisterObjectImpl(const std::string& uri);

	void unregisterSkeleton();

	Poco::RemotingNG::ORB* _pORB;
};


inline Poco::AutoPtr<IoT::PasswdService::PasswdRemoteObject> PasswdServerHelper::createRemoteObject(Poco::SharedPtr<IoT::PasswdService::Passwd> pServiceObject, const Poco::RemotingNG::Identifiable::ObjectId& oid)
{
	return PasswdServerHelper::instance().createRemoteObjectImpl(pServiceObject, oid);
}


inline std::string PasswdServerHelper::registerObject(Poco::SharedPtr<IoT::PasswdService::Passwd> pServiceObject, const Poco::RemotingNG::Identifiable::ObjectId& oid, const std::string& listenerId)
{
	return PasswdServerHelper::instance().registerObjectImpl(createRemoteObject(pServiceObject, oid), listenerId);
}


inline std::string PasswdServerHelper::registerRemoteObject(Poco::AutoPtr<IoT::PasswdService::PasswdRemoteObject> pRemoteObject, const std::string& listenerId)
{
	return PasswdServerHelper::instance().registerObjectImpl(pRemoteObject, listenerId);
}


inline void PasswdServerHelper::unregisterObject(const std::string& uri)
{
	PasswdServerHelper::instance().unregisterObjectImpl(uri);
}


} // namespace PasswdService
} // namespace IoT


REMOTING_SPECIALIZE_SERVER_HELPER(IoT::PasswdService, Passwd)


#endif // IoT_Passwd_PasswdServerHelper_INCLUDED

