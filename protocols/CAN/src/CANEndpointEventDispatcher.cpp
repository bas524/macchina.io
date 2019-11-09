//
// CANEndpointEventDispatcher.cpp
//
// Library: IoT/CAN
// Package: Generated
// Module:  CANEndpointEventDispatcher
//
// This file has been generated.
// Warning: All changes to this will be lost when the file is re-generated.
//
// Copyright (c) 2017, Applied Informatics Software Engineering GmbH.
// All rights reserved.
// 
// SPDX-License-Identifier: Apache-2.0
//


#include "IoT/CAN/CANEndpointEventDispatcher.h"
#include "IoT/CAN/CANFDFrameDeserializer.h"
#include "IoT/CAN/CANFDFrameSerializer.h"
#include "Poco/Delegate.h"
#include "Poco/RemotingNG/Deserializer.h"
#include "Poco/RemotingNG/RemotingException.h"
#include "Poco/RemotingNG/Serializer.h"
#include "Poco/RemotingNG/TypeDeserializer.h"
#include "Poco/RemotingNG/TypeSerializer.h"
#include "Poco/RemotingNG/URIUtility.h"


namespace IoT {
namespace CAN {


CANEndpointEventDispatcher::CANEndpointEventDispatcher(CANEndpointRemoteObject* pRemoteObject, const std::string& protocol):
	Poco::RemotingNG::EventDispatcher(protocol),
	_pRemoteObject(pRemoteObject)
{
	_pRemoteObject->frameReceived += Poco::delegate(this, &CANEndpointEventDispatcher::event__frameReceived);
}


CANEndpointEventDispatcher::~CANEndpointEventDispatcher()
{
	try
	{
		_pRemoteObject->frameReceived -= Poco::delegate(this, &CANEndpointEventDispatcher::event__frameReceived);
	}
	catch (...)
	{
		poco_unexpected();
	}
}


void CANEndpointEventDispatcher::event__frameReceived(const void* pSender, const IoT::CAN::CANFDFrame& data)
{
	if (pSender)
	{
		Poco::Clock now;
		Poco::FastMutex::ScopedLock lock(_mutex);
		SubscriberMap::iterator it = _subscribers.begin();
		while (it != _subscribers.end())
		{
			if (it->second->expireTime != 0 && it->second->expireTime < now)
			{
				SubscriberMap::iterator itDel(it++);
				_subscribers.erase(itDel);
			}
			else
			{
				try
				{
					event__frameReceivedImpl(it->first, data);
				}
				catch (Poco::RemotingNG::RemoteException&)
				{
					throw;
				}
				catch (Poco::Exception&)
				{
				}
				++it;
			}
		}
	}
}


void CANEndpointEventDispatcher::event__frameReceivedImpl(const std::string& subscriberURI, const IoT::CAN::CANFDFrame& data)
{
	remoting__staticInitBegin(REMOTING__NAMES);
	static const std::string REMOTING__NAMES[] = {"frameReceived","subscriberURI","data"};
	remoting__staticInitEnd(REMOTING__NAMES);
	Poco::RemotingNG::Transport& remoting__trans = transportForSubscriber(subscriberURI);
	Poco::ScopedLock<Poco::RemotingNG::Transport> remoting__lock(remoting__trans);
	Poco::RemotingNG::Serializer& remoting__ser = remoting__trans.beginMessage(_pRemoteObject->remoting__objectId(), _pRemoteObject->remoting__typeId(), REMOTING__NAMES[0], Poco::RemotingNG::SerializerBase::MESSAGE_EVENT);
	remoting__ser.serializeMessageBegin(REMOTING__NAMES[0], Poco::RemotingNG::SerializerBase::MESSAGE_EVENT);
	Poco::RemotingNG::TypeSerializer<IoT::CAN::CANFDFrame >::serialize(REMOTING__NAMES[2], data, remoting__ser);
	remoting__ser.serializeMessageEnd(REMOTING__NAMES[0], Poco::RemotingNG::SerializerBase::MESSAGE_EVENT);
	remoting__trans.sendMessage(_pRemoteObject->remoting__objectId(), _pRemoteObject->remoting__typeId(), REMOTING__NAMES[0], Poco::RemotingNG::SerializerBase::MESSAGE_EVENT);
}


const std::string CANEndpointEventDispatcher::DEFAULT_NS("");
} // namespace CAN
} // namespace IoT

