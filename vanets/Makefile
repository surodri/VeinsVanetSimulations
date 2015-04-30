#
# OMNeT++/OMNEST Makefile for vanets
#
# This file was generated with the command:
#  opp_makemake -f --deep -O out -I../inet/src/linklayer/ieee80211/radio -I../inet/src/networklayer/routing/aodv -I../veins/src/veins/base/connectionManager -I../inet/src/networklayer/common -I../veins/src -I../veins/src/veins/base/utils -I../inet/src -I../inet/src/networklayer/icmpv6 -I../inet/src/world/obstacles -I../inet/src/networklayer/xmipv6 -I../inet/src/networklayer/contract -I../inet/src/networklayer/autorouting/ipv4 -I../inet/src/util -I../inet/src/linklayer/common -I../inet/src/transport/contract -I../inet/src/status -I../inet/src/linklayer/radio/propagation -I../inet/src/linklayer/ieee80211/radio/errormodel -I../inet/src/linklayer/radio -I../inet/src/util/headerserializers/tcp -I../inet/src/networklayer/ipv4 -I../inet/src/mobility/contract -I../inet/src/util/headerserializers/ipv4 -I../inet/src/base -I../inet/src/util/headerserializers -I../inet/src/world/radio -I../inet/src/linklayer/ieee80211/mac -I../inet/src/transport/sctp -I../inet/src/networklayer/ipv6 -I../inet/src/util/headerserializers/udp -I../inet/src/networklayer/ipv6tunneling -I../inet/src/util/headerserializers/ipv6 -I../inet/src/battery/models -I../inet/src/applications/pingapp -I../inet/src/linklayer/contract -I../inet/src/util/headerserializers/sctp -I../veins/src/veins/modules -I../inet/src/transport/tcp_common -I../inet/src/networklayer/arp -I../veins/src/veins/modules/obstacle -I../inet/src/transport/udp -I../veins/src/veins/base/messages -L../inet/out/$$\(CONFIGNAME\)/src -L../veins/out/$$\(CONFIGNAME\)/src -linet -lveins -DINET_IMPORT -KINET_PROJ=../inet -KVEINS_PROJ=../veins
#

# Name of target to be created (-o option)
TARGET = vanets$(EXE_SUFFIX)

# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I../inet/src/linklayer/ieee80211/radio \
    -I../inet/src/networklayer/routing/aodv \
    -I../veins/src/veins/base/connectionManager \
    -I../inet/src/networklayer/common \
    -I../veins/src \
    -I../veins/src/veins/base/utils \
    -I../inet/src \
    -I../inet/src/networklayer/icmpv6 \
    -I../inet/src/world/obstacles \
    -I../inet/src/networklayer/xmipv6 \
    -I../inet/src/networklayer/contract \
    -I../inet/src/networklayer/autorouting/ipv4 \
    -I../inet/src/util \
    -I../inet/src/linklayer/common \
    -I../inet/src/transport/contract \
    -I../inet/src/status \
    -I../inet/src/linklayer/radio/propagation \
    -I../inet/src/linklayer/ieee80211/radio/errormodel \
    -I../inet/src/linklayer/radio \
    -I../inet/src/util/headerserializers/tcp \
    -I../inet/src/networklayer/ipv4 \
    -I../inet/src/mobility/contract \
    -I../inet/src/util/headerserializers/ipv4 \
    -I../inet/src/base \
    -I../inet/src/util/headerserializers \
    -I../inet/src/world/radio \
    -I../inet/src/linklayer/ieee80211/mac \
    -I../inet/src/transport/sctp \
    -I../inet/src/networklayer/ipv6 \
    -I../inet/src/util/headerserializers/udp \
    -I../inet/src/networklayer/ipv6tunneling \
    -I../inet/src/util/headerserializers/ipv6 \
    -I../inet/src/battery/models \
    -I../inet/src/applications/pingapp \
    -I../inet/src/linklayer/contract \
    -I../inet/src/util/headerserializers/sctp \
    -I../veins/src/veins/modules \
    -I../inet/src/transport/tcp_common \
    -I../inet/src/networklayer/arp \
    -I../veins/src/veins/modules/obstacle \
    -I../inet/src/transport/udp \
    -I../veins/src/veins/base/messages \
    -I. \
    -Isrc \
    -Isrc/results \
    -Itest \
    -Itest/Temporary \
    -Itest/work \
    -Itest/work/MetricsNed \
    -Itest/work/MetricsNedScalar \
    -Itest/work/MetricsNedScalar/results \
    -Itest/work/MetricsTests \
    -Itest/work/out \
    -Itest/work/out/gcc-debug \
    -Itest/work/out/gcc-debug/MetricsTests

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS = -L../inet/out/$(CONFIGNAME)/src -L../veins/out/$(CONFIGNAME)/src  -linet -lveins
LIBS += -Wl,-rpath,`abspath ../inet/out/$(CONFIGNAME)/src` -Wl,-rpath,`abspath ../veins/out/$(CONFIGNAME)/src`

# Output directory
PROJECT_OUTPUT_DIR = out
PROJECTRELATIVE_PATH =
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc and .msg files
OBJS = $O/src/Metrics.o $O/test/work/MetricsTests/test.o

# Message files
MSGFILES =

# Other makefile variables (-K)
INET_PROJ=../inet
VEINS_PROJ=../veins

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

COPTS = $(CFLAGS) -DINET_IMPORT $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
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
	$(Q)-rm -f vanets vanets.exe libvanets.so libvanets.a libvanets.dll libvanets.dylib
	$(Q)-rm -f ./*_m.cc ./*_m.h
	$(Q)-rm -f src/*_m.cc src/*_m.h
	$(Q)-rm -f src/results/*_m.cc src/results/*_m.h
	$(Q)-rm -f test/*_m.cc test/*_m.h
	$(Q)-rm -f test/Temporary/*_m.cc test/Temporary/*_m.h
	$(Q)-rm -f test/work/*_m.cc test/work/*_m.h
	$(Q)-rm -f test/work/MetricsNed/*_m.cc test/work/MetricsNed/*_m.h
	$(Q)-rm -f test/work/MetricsNedScalar/*_m.cc test/work/MetricsNedScalar/*_m.h
	$(Q)-rm -f test/work/MetricsNedScalar/results/*_m.cc test/work/MetricsNedScalar/results/*_m.h
	$(Q)-rm -f test/work/MetricsTests/*_m.cc test/work/MetricsTests/*_m.h
	$(Q)-rm -f test/work/out/*_m.cc test/work/out/*_m.h
	$(Q)-rm -f test/work/out/gcc-debug/*_m.cc test/work/out/gcc-debug/*_m.h
	$(Q)-rm -f test/work/out/gcc-debug/MetricsTests/*_m.cc test/work/out/gcc-debug/MetricsTests/*_m.h

cleanall: clean
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(qecho) Creating dependencies...
	$(Q)$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc src/*.cc src/results/*.cc test/*.cc test/Temporary/*.cc test/work/*.cc test/work/MetricsNed/*.cc test/work/MetricsNedScalar/*.cc test/work/MetricsNedScalar/results/*.cc test/work/MetricsTests/*.cc test/work/out/*.cc test/work/out/gcc-debug/*.cc test/work/out/gcc-debug/MetricsTests/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/src/Metrics.o: src/Metrics.cc \
	$(INET_PROJ)/src/base/Compat.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	src/Metrics.h
$O/test/work/MetricsTests/test.o: test/work/MetricsTests/test.cc \
	$(INET_PROJ)/src/base/Compat.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	src/Metrics.h \
	test/work/MetricsTests/TestMetrics.h

