#
# OMNeT++/OMNEST Makefile for work
#
# This file was generated with the command:
#  opp_makemake -f --deep -P . --no-deep-includes -I.././../src -I.././../src/results -I.././../src/singlechannel -I./Mac1609_4_Metrics -I./Metrics_NedScalar -I./Metrics_PacketsDeliveredToMetrics -I./Metrics_Throughput -I./NetworkSimulation_Parameters -I./ResultsUtil_Test -I./Metrics_Throughput -I./../../../vanets/src -I./lib -I./../../../inet/src/base -I./../../../veins/src/ #-I./../../../../googletest/googletest/include -L../../src/ -lvanets -L../../../veins/src -lveins
#

# Name of target to be created (-o option)
TARGET = work$(EXE_SUFFIX)

# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I../../src \
    -I../../src/results \
    -I../../src/singlechannel \
    -I./Mac1609_4_Metrics \
    -I./Metrics_NedScalar \
    -I./Metrics_PacketsDeliveredToMetrics \
    -I./Metrics_Throughput \
    -I./NetworkSimulation_Parameters \
    -I./ResultsUtil_Test \
    -I./Metrics_Throughput \
    -I./../../../vanets/src \
    -I./lib \
    -I./../../../inet/src/base \
    -I./../../../veins/src/

# Additional object and library files to link with
EXTRA_OBJS = #-I./../../../../googletest/googletest/include

# Additional libraries (-L, -l options)
LIBS = -L../../src/ -L../../../veins/src  -lvanets -lveins
LIBS += -Wl,-rpath,`abspath ../../src/` -Wl,-rpath,`abspath ../../../veins/src`

# Output directory
PROJECT_OUTPUT_DIR = out
PROJECTRELATIVE_PATH =
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc and .msg files
OBJS = $O/Mac1609_4_Metrics/test.o $O/Metrics_PacketsDeliveredToMetrics/test.o $O/Metrics_Throughput/test.o $O/NetworkSimulation_Parameters/test.o $O/ResultsUtil_Test/test.o

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
	$(Q)-rm -f Mac1609_4_Metrics/*_m.cc Mac1609_4_Metrics/*_m.h
	$(Q)-rm -f Metrics_NedScalar/*_m.cc Metrics_NedScalar/*_m.h
	$(Q)-rm -f Metrics_NedScalar/singlechannel/*_m.cc Metrics_NedScalar/singlechannel/*_m.h
	$(Q)-rm -f Metrics_PacketsDeliveredToMetrics/*_m.cc Metrics_PacketsDeliveredToMetrics/*_m.h
	$(Q)-rm -f Metrics_Throughput/*_m.cc Metrics_Throughput/*_m.h
	$(Q)-rm -f NetworkSimulation_Parameters/*_m.cc NetworkSimulation_Parameters/*_m.h
	$(Q)-rm -f ResultsUtil_Test/*_m.cc ResultsUtil_Test/*_m.h

cleanall: clean
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(qecho) Creating dependencies...
	$(Q)$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc Mac1609_4_Metrics/*.cc Metrics_NedScalar/*.cc Metrics_NedScalar/singlechannel/*.cc Metrics_PacketsDeliveredToMetrics/*.cc Metrics_Throughput/*.cc NetworkSimulation_Parameters/*.cc ResultsUtil_Test/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/Mac1609_4_Metrics/test.o: Mac1609_4_Metrics/test.cc \
  ../../src/results/../../../veins/src/veins/modules/mac/ieee80211p/Mac1609_4.h \
  ../../src/results/../../../veins/src/veins/base/utils/MiXiMDefs.h \
  ./../../../veins/src//veins/base/messages/ChannelSenseRequest_m.h \
  ./../../../veins/src//veins/base/utils/Coord.h \
  ./../../../veins/src//veins/base/phyLayer/AnalogueModel.h \
  ../../src/Metrics.h \
  ./../../../veins/src//veins/base/utils/PassedMessage.h \
  ./../../../veins/src//veins/base/phyLayer/MappingUtils.h \
  ./../../../veins/src//veins/modules/messages/Mac80211Pkt_m.h \
  ./../../../veins/src//veins/base/phyLayer/Mapping.h \
  ./../../../veins/src//veins/modules/utility/ConstsPhy.h \
  ./../../../veins/src//veins/base/modules/BaseMobility.h \
  ./Mac1609_4_Metrics/../../../src/Mac16094Metrics.h \
  ./../../../veins/src//veins/base/phyLayer/Signal_.h \
  ./../../../veins/src//veins/base/phyLayer/ChannelInfo.h \
  ./../../../veins/src//veins/base/connectionManager/BaseConnectionManager.h \
  ./../../../veins/src//veins/base/phyLayer/PhyUtils.h \
  ./../../../veins/src//veins/base/phyLayer/Decider.h \
  ./../../../veins/src//veins/base/messages/MacPkt_m.h \
  ./../../../veins/src//veins/base/connectionManager/NicEntry.h \
  ./../../../veins/src//veins/base/utils/SimpleAddress.h \
  ./../../../veins/src//veins/base/modules/BaseLayer.h \
  ./../../../veins/src//veins/base/phyLayer/Interpolation.h \
  ./../../../veins/src//veins/base/phyLayer/MappingBase.h \
  ./../../../veins/src//veins/modules/mac/ieee80211p/WaveAppToMac1609_4Interface.h \
  ./../../../inet/src/base/INETDefs.h \
  ./../../../veins/src//veins/modules/phy/SNRThresholdDecider.h \
  ./../../../veins/src//veins/modules/analogueModel/SimplePathlossModel.h \
  ./../../../veins/src//veins/modules/phy/PhyLayer80211p.h \
  ./../../../veins/src//veins/base/phyLayer/MacToPhyInterface.h \
  ./../../../veins/src//veins/base/utils/Move.h \
  ../../src/results/../../../veins/src/veins/base/modules/BaseLayer.h \
  ./../../../veins/src//veins/base/modules/BaseBattery.h \
  ./Mac1609_4_Metrics/Mac16094MetricsTest.h \
  ./../../../veins/src//veins/base/connectionManager/ChannelAccess.h \
  ./../../../veins/src//veins/base/utils/FWMath.h \
  ./../../../veins/src//veins/base/utils/miximkerneldefs.h \
  ./Mac1609_4_Metrics/../../../src/Metrics.h \
  ./../../../veins/src//veins/base/phyLayer/BasePhyLayer.h \
  ./../../../inet/src/base/Compat.h \
  ./../../../veins/src//veins/base/utils/FindModule.h \
  ../../src/results/../../../veins/src/veins/base/utils/miximkerneldefs.h \
  ./../../../veins/src//veins/modules/analogueModel/JakesFading.h \
  ./../../../veins/src//veins/modules/phy/Decider80211p.h \
  ./../../../veins/src//veins/base/utils/HostState.h \
  ./../../../veins/src//veins/base/utils/NetwToMacControlInfo.h \
  ./../../../veins/src//veins/base/modules/BatteryAccess.h \
  ./../../../veins/src//veins/base/phyLayer/MacToPhyControlInfo.h \
  ./../../../veins/src//veins/modules/phy/Decider80211pToPhy80211pInterface.h \
  ./../../../veins/src//veins/modules/mac/ieee80211p/Mac80211pToPhy11pInterface.h \
  ./../../../veins/src//veins/base/phyLayer/DeciderToPhyInterface.h \
  ./../../../veins/src//veins/modules/messages/WaveShortMessage_m.h \
  ./../../../veins/src//veins/base/phyLayer/BaseDecider.h \
  ./../../../veins/src//veins/base/utils/MiXiMDefs.h \
  ./../../../veins/src//veins/modules/utility/Consts80211p.h \
  ./../../../veins/src//veins/base/phyLayer/ChannelState.h \
  ./../../../veins/src//veins/base/modules/BaseModule.h \
  ./../../../veins/src//veins/base/messages/AirFrame_m.h \
  ./../../../veins/src//veins/base/modules/BaseWorldUtility.h \
  ./../../../veins/src//veins/modules/analogueModel/LogNormalShadowing.h \
  ./../../../veins/src//veins/base/modules/BaseMacLayer.h
$O/Metrics_PacketsDeliveredToMetrics/test.o: Metrics_PacketsDeliveredToMetrics/test.cc \
  ./../../../inet/src/base/INETDefs.h \
  ./../../../inet/src/base/Compat.h
$O/Metrics_Throughput/test.o: Metrics_Throughput/test.cc \
  ./Metrics_Throughput/TestMetrics2.h \
  ./../../../inet/src/base/INETDefs.h \
  ./Mac1609_4_Metrics/../../../src/Metrics.h \
  ./../../../inet/src/base/Compat.h
$O/NetworkSimulation_Parameters/test.o: NetworkSimulation_Parameters/test.cc
$O/ResultsUtil_Test/test.o: ResultsUtil_Test/test.cc \
  ./ResultsUtil_Test/ResultsUtilTest.h \
  ./Mac1609_4_Metrics/../../../src/ResultsUtil.h
