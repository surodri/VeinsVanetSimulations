#
# OMNeT++/OMNEST Makefile for TemporaryFolder
#
# This file was generated with the command:
#  opp_makemake -f --deep -O out
#

# Name of target to be created (-o option)
TARGET = TemporaryFolder$(EXE_SUFFIX)

# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(QTENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)
#USERIF_LIBS = $(QTENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I. \
    -Itest \
    -Itest/work \
    -Itest/work/DummyTest \
    -Itest/work/FooCrap \
    -Itest/work/out \
    -Itest/work/out/gcc-debug \
    -Itest/work/out/gcc-debug/DummyTest

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS =

# Output directory
PROJECT_OUTPUT_DIR = out
PROJECTRELATIVE_PATH =
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc, .msg and .sm files
OBJS = $O/test/work/DummyTest/test.o $O/test/work/FooCrap/test.o

# Message files
MSGFILES =

# SM files
SMFILES =

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
SMCOPTS =

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

.PHONY: all clean cleanall depend msgheaders smheaders

.SUFFIXES: .cc

$O/%.o: %.cc $(COPTS_FILE)
	@$(MKPATH) $(dir $@)
	$(qecho) "$<"
	$(Q)$(CXX) -c $(CXXFLAGS) $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(qecho) MSGC: $<
	$(Q)$(MSGC) -s _m.cc $(MSGCOPTS) $?

%_sm.cc %_sm.h: %.sm
	$(qecho) SMC: $<
	$(Q)$(SMC) -c++ -suffix cc $(SMCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

smheaders: $(SMFILES:.sm=_sm.h)

clean:
	$(qecho) Cleaning...
	$(Q)-rm -rf $O
	$(Q)-rm -f TemporaryFolder TemporaryFolder.exe libTemporaryFolder.so libTemporaryFolder.a libTemporaryFolder.dll libTemporaryFolder.dylib
	$(Q)-rm -f ./*_m.cc ./*_m.h ./*_sm.cc ./*_sm.h
	$(Q)-rm -f test/*_m.cc test/*_m.h test/*_sm.cc test/*_sm.h
	$(Q)-rm -f test/work/*_m.cc test/work/*_m.h test/work/*_sm.cc test/work/*_sm.h
	$(Q)-rm -f test/work/DummyTest/*_m.cc test/work/DummyTest/*_m.h test/work/DummyTest/*_sm.cc test/work/DummyTest/*_sm.h
	$(Q)-rm -f test/work/FooCrap/*_m.cc test/work/FooCrap/*_m.h test/work/FooCrap/*_sm.cc test/work/FooCrap/*_sm.h
	$(Q)-rm -f test/work/out/*_m.cc test/work/out/*_m.h test/work/out/*_sm.cc test/work/out/*_sm.h
	$(Q)-rm -f test/work/out/gcc-debug/*_m.cc test/work/out/gcc-debug/*_m.h test/work/out/gcc-debug/*_sm.cc test/work/out/gcc-debug/*_sm.h
	$(Q)-rm -f test/work/out/gcc-debug/DummyTest/*_m.cc test/work/out/gcc-debug/DummyTest/*_m.h test/work/out/gcc-debug/DummyTest/*_sm.cc test/work/out/gcc-debug/DummyTest/*_sm.h

cleanall: clean
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(qecho) Creating dependencies...
	$(Q)$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES) $(SM_CC_FILES)  ./*.cc test/*.cc test/work/*.cc test/work/DummyTest/*.cc test/work/FooCrap/*.cc test/work/out/*.cc test/work/out/gcc-debug/*.cc test/work/out/gcc-debug/DummyTest/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/test/work/DummyTest/test.o: test/work/DummyTest/test.cc
$O/test/work/FooCrap/test.o: test/work/FooCrap/test.cc

