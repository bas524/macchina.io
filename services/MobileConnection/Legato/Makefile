#
# Makefile
#
# Makefile for macchina.io Legato MobileConnectionService bundle
#

include $(POCO_BASE)/build/rules/global

ifneq (,$(findstring debug,$(DEFAULT_TARGET)))
        BUNDLE_TOOL = $(POCO_BASE)/OSP/BundleCreator/$(POCO_HOST_BINDIR)/bundled
else
        BUNDLE_TOOL = $(POCO_BASE)/OSP/BundleCreator/$(POCO_HOST_BINDIR)/bundle
endif

INCLUDE += -I$(PROJECT_BASE)/services/MobileConnection/include

objects = MobileConnectionServiceImpl BundleActivator

target         = io.macchina.services.mobileconnection.legato
target_version = 1
target_libs    = IoTMobileConnection PocoOSP PocoRemotingNG PocoUtil PocoXML PocoFoundation

postbuild      = $(SET_LD_LIBRARY_PATH) $(BUNDLE_TOOL) -n$(OSNAME) -a$(OSARCH) -o../../bundles Legato.bndlspec

include $(POCO_BASE)/build/rules/dylib
