//
// BundleActivator.cpp
//
// $Id$
//
// Copyright (c) 2017, IVK CJSC.
// All rights reserved.
//
//


#include "PasswdServiceImpl.h"
#include "IoT/Passwd/PasswdServerHelper.h"
#include "Poco/OSP/BundleActivator.h"
#include "Poco/OSP/BundleContext.h"
#include "Poco/OSP/Bundle.h"
#include "Poco/OSP/ServiceRegistry.h"
#include "Poco/OSP/ServiceRef.h"
#include "Poco/OSP/ServiceFinder.h"
#include "Poco/OSP/PreferencesService.h"
#include "Poco/LoggingRegistry.h"
#include "Poco/Delegate.h"
#include "Poco/ClassLibrary.h"


using Poco::OSP::BundleContext;
using Poco::OSP::ServiceRegistry;
using Poco::OSP::ServiceRef;
using Poco::OSP::Properties;


namespace IoT {
namespace PasswdService {


class BundleActivator: public Poco::OSP::BundleActivator
{
public:
	typedef Poco::RemotingNG::ServerHelper<IoT::PasswdService::Passwd> ServerHelper;

	BundleActivator()
	{
	}
	
    ~BundleActivator()
	{
	}

	void start(BundleContext::Ptr pContext)
	{
		_pContext = pContext;

		Poco::OSP::PreferencesService::Ptr pPrefs = Poco::OSP::ServiceFinder::find<Poco::OSP::PreferencesService>(pContext);
		
		_pPasswdService = new PasswdServiceImpl(pContext);
		std::string oid("io.macchina.services.passwdservice");
		ServerHelper::RemoteObjectPtr pPasswdServiceRemoteObject = ServerHelper::createRemoteObject(_pPasswdService, oid);		
		_pServiceRef = pContext->registry().registerService(oid, pPasswdServiceRemoteObject, Properties());
	}
		
	void stop(BundleContext::Ptr pContext)
	{
		pContext->registry().unregisterService(_pServiceRef);
		_pServiceRef = 0;
		_pPasswdService = 0;
		_pContext = 0;
		
		ServerHelper::shutdown();
	}

protected:
	
private:
	Poco::OSP::BundleContext::Ptr _pContext;
	Poco::SharedPtr<IoT::PasswdService::Passwd> _pPasswdService;
	Poco::OSP::ServiceRef::Ptr _pServiceRef;
};


} } // namespace IoT::PasswdService


POCO_BEGIN_MANIFEST(Poco::OSP::BundleActivator)
	POCO_EXPORT_CLASS(IoT::PasswdService::BundleActivator)
POCO_END_MANIFEST
