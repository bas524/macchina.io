//
// CameraServerHelper.h
//
// Library: IoT/Devices
// Package: Generated
// Module:  CameraServerHelper
//
// This file has been generated.
// Warning: All changes to this will be lost when the file is re-generated.
//
// Copyright (c) 2014-2015, Applied Informatics Software Engineering GmbH.
// All rights reserved.
// 
// SPDX-License-Identifier: Apache-2.0
//


#ifndef IoT_Devices_CameraServerHelper_INCLUDED
#define IoT_Devices_CameraServerHelper_INCLUDED


#include "IoT/Devices/Camera.h"
#include "IoT/Devices/CameraRemoteObject.h"
#include "IoT/Devices/ICamera.h"
#include "Poco/RemotingNG/Identifiable.h"
#include "Poco/RemotingNG/ORB.h"
#include "Poco/RemotingNG/ServerHelper.h"


namespace IoT {
namespace Devices {


class CameraServerHelper
	/// The base class for image sensors, also known as cameras.
{
public:
	typedef IoT::Devices::Camera Service;

	CameraServerHelper();
		/// Creates a CameraServerHelper.

	~CameraServerHelper();
		/// Destroys the CameraServerHelper.

	static Poco::AutoPtr<IoT::Devices::CameraRemoteObject> createRemoteObject(Poco::SharedPtr<IoT::Devices::Camera> pServiceObject, const Poco::RemotingNG::Identifiable::ObjectId& oid);
		/// Creates and returns a RemoteObject wrapper for the given IoT::Devices::Camera instance.

	static void enableEvents(const std::string& uri, const std::string& protocol);
		/// Enables remote events for the RemoteObject identified by the given URI.
		///
		/// Events will be delivered using the Transport for the given protocol.
		/// Can be called multiple times for the same URI with different protocols.

	static std::string registerObject(Poco::SharedPtr<IoT::Devices::Camera> pServiceObject, const Poco::RemotingNG::Identifiable::ObjectId& oid, const std::string& listenerId);
		/// Creates a RemoteObject wrapper for the given IoT::Devices::Camera instance
		/// and registers it with the ORB and the Listener instance
		/// uniquely identified by the Listener's ID.
		/// 
		///	Returns the URI created for the object.

	static std::string registerRemoteObject(Poco::AutoPtr<IoT::Devices::CameraRemoteObject> pRemoteObject, const std::string& listenerId);
		/// Registers the given RemoteObject with the ORB and the Listener instance
		/// uniquely identified by the Listener's ID.
		/// 
		///	Returns the URI created for the object.

	static void shutdown();
		/// Removes the Skeleton for IoT::Devices::Camera from the ORB.

	static void unregisterObject(const std::string& uri);
		/// Unregisters a service object identified by URI from the ORB.

private:
	static Poco::AutoPtr<IoT::Devices::CameraRemoteObject> createRemoteObjectImpl(Poco::SharedPtr<IoT::Devices::Camera> pServiceObject, const Poco::RemotingNG::Identifiable::ObjectId& oid);

	void enableEventsImpl(const std::string& uri, const std::string& protocol);

	static CameraServerHelper& instance();
		/// Returns a static instance of the helper class.

	std::string registerObjectImpl(Poco::AutoPtr<IoT::Devices::CameraRemoteObject> pRemoteObject, const std::string& listenerId);

	void registerSkeleton();

	void unregisterObjectImpl(const std::string& uri);

	void unregisterSkeleton();

	Poco::RemotingNG::ORB* _pORB;
};


inline Poco::AutoPtr<IoT::Devices::CameraRemoteObject> CameraServerHelper::createRemoteObject(Poco::SharedPtr<IoT::Devices::Camera> pServiceObject, const Poco::RemotingNG::Identifiable::ObjectId& oid)
{
	return CameraServerHelper::instance().createRemoteObjectImpl(pServiceObject, oid);
}


inline void CameraServerHelper::enableEvents(const std::string& uri, const std::string& protocol)
{
	CameraServerHelper::instance().enableEventsImpl(uri, protocol);
}


inline std::string CameraServerHelper::registerObject(Poco::SharedPtr<IoT::Devices::Camera> pServiceObject, const Poco::RemotingNG::Identifiable::ObjectId& oid, const std::string& listenerId)
{
	return CameraServerHelper::instance().registerObjectImpl(createRemoteObject(pServiceObject, oid), listenerId);
}


inline std::string CameraServerHelper::registerRemoteObject(Poco::AutoPtr<IoT::Devices::CameraRemoteObject> pRemoteObject, const std::string& listenerId)
{
	return CameraServerHelper::instance().registerObjectImpl(pRemoteObject, listenerId);
}


inline void CameraServerHelper::unregisterObject(const std::string& uri)
{
	CameraServerHelper::instance().unregisterObjectImpl(uri);
}


} // namespace Devices
} // namespace IoT


REMOTING_SPECIALIZE_SERVER_HELPER(IoT::Devices, Camera)


#endif // IoT_Devices_CameraServerHelper_INCLUDED

