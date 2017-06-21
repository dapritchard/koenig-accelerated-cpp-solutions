
# chapter and compiler settings ------------------------------------------------

EXER_PREFIX := exer07_
TEST_PREFIX := test07_
UNIT_PREFIX := utest_
RUN_PREFIX := run_
TESTDIR := ../testing
INCDIR := /usr/local/include
LIBDIR := /usr/local/lib
RPATH := -Wl,-rpath=$(LIBDIR)

# specify C++ flags.  The implicit rule used to link together object files
# utilizes $(CC) which by default has value cc, so this needs to be changed to
# invoke the C++ toolchain.
CXXFLAGS := -Wall -g3
CC := $(CXX)


# create program and testing variables -----------------------------------------

# these variables are used later as prerequisites for targets

# names of the executables, obtained by stripping the .cpp suffix
executables := $(sort $(basename $(wildcard $(EXER_PREFIX)*.cpp) ) )

# names of the Bash test scripts
test_targets := $(sort $(basename $(wildcard $(TEST_PREFIX)*.sh) ) )

# names of the C++ unit tests
unit_tests := $(sort $(basename $(wildcard $(UNIT_PREFIX)*.cpp) ) )

# dummy names used to initiate execution of unit tests
unit_targets := $(addprefix $(RUN_PREFIX), $(unit_tests))




# primary makefile targets -----------------------------------------------------

.PHONY : all test utest clean clobber \
	$(TEST_PREFIX)% $(RUN_PREFIX)$(UNIT_PREFIX)%

# default rule
all : $(executables)

# all of the builds needed to performing unit testing
utest : $(unit_tests) $(executables)

# run all unit and system tests
test : $(unit_targets) $(test_targets) 

clean :
	rm -f *.o

clobber :
	rm -f *.o $(executables) $(unit_tests)




# define implicit rules --------------------------------------------------------

# define implicit rules for testing.  The shell prints the test program name and
# executes the test.  If the test is successful then the "test pass" message is
# written and the OR statement is not evaluated.  If the test fails, then the
# last AND statement is not evaluated but the OR statement is, which writes a
# "test fail" message.

$(TEST_PREFIX)% : $(TEST_PREFIX)%.sh $(EXER_PREFIX)%
	@printf $< && ./$< > /dev/null && printf ":    pass\n" \
		|| printf ":    ** test failure **\n"

$(RUN_PREFIX)$(UNIT_PREFIX)% : $(UNIT_PREFIX)%
	@printf $< && ./$< > /dev/null && printf ":    pass\n" \
		|| printf ":    ** test failure **\n"

# for debugging the makefile.  Print out a variable name `varname' by running
# `make print-varname'
print-%:
	@echo '$*=$($*)'




# exercise build rules ---------------------------------------------------------

exer07_03.o : split.h
exer07_03 : split.o

exer07_04.o : split.h
exer07_04 : split.o

exer07_05.o : split.h
exer07_05 : split.o

exer07_06.o : gen_sentence.h
exer07_06 : gen_sentence.o split.o nrand.o

gen_sentence.o : gen_sentence.h split.h nrand.h
gen_sentence : split.o nrand.o



# # unit testing build rules -----------------------------------------------------

# unit tests linked against CppUnit need to be compiled using the C++11
# standard, and the compiler needs to be informed where to find the header files
# and shared objects

utest_%.o : override CXXFLAGS += -std=c++11
utest_% : override LDFLAGS += -L$(LIBDIR) $(RPATH)
utest_% : override LDLIBS += -lcppunit

# # begin unit testing recipe section

utest_gen_sentence.o : gen_sentence.h split.h nrand.h
utest_gen_sentence : gen_sentence.o split.o nrand.o
