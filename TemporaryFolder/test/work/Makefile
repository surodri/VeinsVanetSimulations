#
# OMNeT++/OMNEST Makefile for work
#
# This file was generated with the command:
#  opp_makemake -f --deep -lveins -L../../../veins/src/ -P . --no-deep-includes -I../../../veins/src/ -I../../../veins/src/veins -I../../../veins/src/veins/modules -I../../../veins/src/veins/modules/phy -I../../../veins/src/veins/modules/mac -I../../../veins/src/veins/modules/mac/ieee80211p -I../../../veins/src/veins/modules/obstacle -I../../../veins/src/veins/modules/analogueModel -I../../../veins/src/veins/modules/nic -I../../../veins/src/veins/modules/messages -I../../../veins/src/veins/modules/application -I../../../veins/src/veins/modules/application/traci -I../../../veins/src/veins/modules/application/ieee80211p -I../../../veins/src/veins/modules/utility -I../../../veins/src/veins/modules/mobility -I../../../veins/src/veins/modules/mobility/traci -I../../../veins/src/veins/modules/world -I../../../veins/src/veins/modules/world/annotations -I../../../veins/src/veins/nodes -I../../../veins/src/veins/base -I../../../veins/src/veins/base/utils -I../../../veins/src/veins/base/modules -I../../../veins/src/veins/base/connectionManager -I../../../veins/src/veins/base/messages -I../../../veins/src/veins/base/phyLayer -I../../../veins/src/scripts -I./lib
#

# Name of target to be created (-o option)
TARGET = work$(EXE_SUFFIX)

# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I../../../veins/src/ \
    -I../../../veins/src/veins \
    -I../../../veins/src/veins/modules \
    -I../../../veins/src/veins/modules/phy \
    -I../../../veins/src/veins/modules/mac \
    -I../../../veins/src/veins/modules/mac/ieee80211p \
    -I../../../veins/src/veins/modules/obstacle \
    -I../../../veins/src/veins/modules/analogueModel \
    -I../../../veins/src/veins/modules/nic \
    -I../../../veins/src/veins/modules/messages \
    -I../../../veins/src/veins/modules/application \
    -I../../../veins/src/veins/modules/application/traci \
    -I../../../veins/src/veins/modules/application/ieee80211p \
    -I../../../veins/src/veins/modules/utility \
    -I../../../veins/src/veins/modules/mobility \
    -I../../../veins/src/veins/modules/mobility/traci \
    -I../../../veins/src/veins/modules/world \
    -I../../../veins/src/veins/modules/world/annotations \
    -I../../../veins/src/veins/nodes \
    -I../../../veins/src/veins/base \
    -I../../../veins/src/veins/base/utils \
    -I../../../veins/src/veins/base/modules \
    -I../../../veins/src/veins/base/connectionManager \
    -I../../../veins/src/veins/base/messages \
    -I../../../veins/src/veins/base/phyLayer \
    -I../../../veins/src/scripts \
    -I./lib

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS = -L../../../veins/src/  -lveins
LIBS += -Wl,-rpath,`abspath ../../../veins/src/`

# Output directory
PROJECT_OUTPUT_DIR = out
PROJECTRELATIVE_PATH =
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc and .msg files
OBJS = $O/DummyTest/test.o $O/FooCrap/test.o

# Message files
MSGFILES =

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc or configuser.vc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIB_SUBDIR = $(OMNETPP_LIB_DIR)/$(TOOLCHAIN_NAME)
OMNETPP_LIBS = -L"$(OMNETPP_LIB_SUBDIR)" -L"$(OMNETPP_LIB_DIR)" -loppmain$D $(USERIF_LIBS) $(KERNEL_LIBS) $(SYS_LIBS)

COPTS = $(CFLAGS)  $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)

# we want to recompile everything if COPTS changes,
# so we store COPTS into $COPTS_FILE and have object
# files depend on it (except when "make depend" was called)
COPTS_FILE = $O/.last-copts
ifneq ($(MAKECMDGOALS),depend)
ifneq ("$(COPTS)","$(shell cat $(COPTS_FILE) 2>/dev/null || echo '')")
$(shell $(MKPATH) "$O" && echo "$(COPTS)" >$(COPTS_FILE))
endif
endif

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# <<<
#------------------------------------------------------------------------------

# Main target
all: $O/$(TARGET)
	$(Q)$(LN) $O/$(TARGET) .

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile
	@$(MKPATH) $O
	@echo Creating executable: $@
	$(Q)$(CXX) $(LDFLAGS) -o $O/$(TARGET)  $(OBJS) $(EXTRA_OBJS) $(AS_NEEDED_OFF) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS)

.PHONY: all clean cleanall depend msgheaders

.SUFFIXES: .cc

$O/%.o: %.cc $(COPTS_FILE)
	@$(MKPATH) $(dir $@)
	$(qecho) "$<"
	$(Q)$(CXX) -c $(CXXFLAGS) $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(qecho) MSGC: $<
	$(Q)$(MSGC) -s _m.cc $(MSGCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

clean:
	$(qecho) Cleaning...
	$(Q)-rm -rf $O
	$(Q)-rm -f work work.exe libwork.so libwork.a libwork.dll libwork.dylib
	$(Q)-rm -f ./*_m.cc ./*_m.h
	$(Q)-rm -f DummyTest/*_m.cc DummyTest/*_m.h
	$(Q)-rm -f FooCrap/*_m.cc FooCrap/*_m.h

cleanall: clean
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(qecho) Creating dependencies...
	$(Q)$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc DummyTest/*.cc FooCrap/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/DummyTest/test.o: DummyTest/test.cc
$O/FooCrap/test.o: FooCrap/test.cc \
  ../../../veins/src//veins/modules/analogueModel/SimplePathlossModel.h \
  ../../../veins/src//veins/base/phyLayer/Interpolation.h \
  ../../../veins/src//veins/base/messages/AirFrame_m.h \
  ../../../veins/src//veins/base/phyLayer/ChannelInfo.h \
  ../../../veins/src//veins/base/phyLayer/DeciderToPhyInterface.h \
  ../../../veins/src//veins/base/utils/MiXiMDefs.h \
  ../../../veins/src//veins/base/utils/Coord.h \
  ../../../veins/src//veins/base/modules/BaseWorldUtility.h \
  ../../../veins/src//veins/modules/phy/Decider80211p.h \
  ../../../veins/src//veins/base/modules/BaseBattery.h \
  ../../../veins/src//veins/base/phyLayer/MappingUtils.h \
  ../../../veins/src//veins/base/phyLayer/ChannelState.h \
  ../../../veins/src//veins/modules/phy/Decider80211pToPhy80211pInterface.h \
  ../../../veins/src//veins/modules/utility/Consts80211p.h \
  ../../../veins/src//veins/modules/analogueModel/LogNormalShadowing.h \
  ../../../veins/src//veins/base/utils/Move.h \
  ../../../veins/src//veins/base/phyLayer/Signal_.h \
  ../../../veins/src//veins/base/phyLayer/Decider.h \
  ../../../veins/src//veins/base/connectionManager/ChannelAccess.h \
  ../../../veins/src//veins/base/phyLayer/BaseDecider.h \
  ../../../veins/src//veins/base/phyLayer/AnalogueModel.h \
  ../../../veins/src//veins/base/utils/FindModule.h \
  ../../../veins/src//veins/base/phyLayer/MappingBase.h \
  ../../../veins/src//veins/base/utils/FWMath.h \
  ../../../veins/src//veins/base/phyLayer/PhyUtils.h \
  ../../../veins/src/veins/modules/phy/PhyLayer80211p.h \
  ../../../veins/src//veins/base/utils/miximkerneldefs.h \
  ../../../veins/src//veins/modules/mac/ieee80211p/Mac80211pToPhy11pInterface.h \
  ../../../veins/src//veins/base/modules/BaseModule.h \
  ../../../veins/src//veins/base/modules/BaseMobility.h \
  ../../../veins/src//veins/modules/analogueModel/JakesFading.h \
  ../../../veins/src//veins/base/utils/HostState.h \
  ../../../veins/src//veins/base/phyLayer/Mapping.h \
  ../../../veins/src//veins/base/phyLayer/MacToPhyInterface.h \
  ../../../veins/src//veins/base/connectionManager/BaseConnectionManager.h \
  ../../../veins/src//veins/base/messages/ChannelSenseRequest_m.h \
  ../../../veins/src//veins/modules/phy/SNRThresholdDecider.h \
  ../../../veins/src//veins/base/phyLayer/BasePhyLayer.h \
  ../../../veins/src//veins/base/connectionManager/NicEntry.h \
  ../../../veins/src//veins/base/modules/BatteryAccess.h
