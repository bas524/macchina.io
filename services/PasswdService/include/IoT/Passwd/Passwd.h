//
// DeviceStatus.h
//
// $Id$
//
// Library: IoT/Passwds
// Package: Passwd
// Module:  Passwd
//
// Basic definitions for the IoT Passwd library.
// This file must be the first file included by every other Core
// header file.
//
// Copyright (c) 2017, IVK CJSC.
// All rights reserved.
//
//


#ifndef IoT_Passwd_INCLUDED
#define IoT_Passwd_INCLUDED


#include "Poco/Poco.h"


//
// The following block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the IoTPasswd_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// IoTPasswd_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
//
#if defined(_WIN32) && defined(POCO_DLL)
	#if defined(IoTPasswd_EXPORTS)
		#define IoTPasswd_API __declspec(dllexport)
	#else
		#define IoTPasswd_API __declspec(dllimport)
	#endif
#endif


#if !defined(IoTPasswd_API)
	#define IoTPasswd_API
#endif


//
// Automatically link Devices library.
//
#if defined(_MSC_VER)
	#if !defined(POCO_NO_AUTOMATIC_LIBS) && !defined(IoTPasswd_EXPORTS)
		#pragma comment(lib, "IoTPasswdService" POCO_LIB_SUFFIX)
	#endif
#endif


#endif // IoT_Passwd_INCLUDED
