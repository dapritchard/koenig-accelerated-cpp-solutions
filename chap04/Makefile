
# chapter and compiler settings ------------------------------------------------

EXER_PREFIX := exer04_
TEST_PREFIX := test04_
UNIT_PREFIX := utest_
RUN_PREFIX := run_
TESTDIR := ../testing

# specify C++ flags.  The implicit rule used to link together object files
# utilizes $(CC) which by default has value cc, so this needs to be changed to
# invoke the C++ toolchain.
CXXFLAGS := -Wall -g3 $(CXXFLAGS)
CC := $(CXX)




# create program and testing variables -----------------------------------------

# these variables are used later as prerequisites for targets

# names of the executables after stripping the .cpp suffix
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

# run all unit tests
test : $(unit_targets) $(test_targets) 

clean :
	rm -f *.o

clobber :
	rm -f *.o $(executables) $(unit_tests)




# lower-level build rules ------------------------------------------------------

exer04_03 : exer04_03.o calc_nchars.o
exer04_04 : exer04_04.o calc_nchars.o calc_seq.o

calc_nchars.o : calc_nchars.h
utest_calc_nchars.o : $(TESTDIR)/UnitTest.h calc_nchars.h
utest_calc_nchars : utest_calc_nchars.o calc_nchars.o $(TESTDIR)/UnitTest.o

utest_ndig_before_after.o : $(TESTDIR)/UnitTest.h calc_nchars.h
utest_ndig_before_after : utest_ndig_before_after.o calc_nchars.o $(TESTDIR)/UnitTest.o

utest_calc_width_prec.o : $(TESTDIR)/UnitTest.h calc_seq.h calc_nchars.h
utest_calc_width_prec : utest_calc_width_prec.o calc_seq.o calc_nchars.o $(TESTDIR)/UnitTest.o

utest_calc_seq.o : $(TESTDIR)/UnitTest.h calc_seq.h
utest_calc_seq : utest_calc_seq.o calc_seq.o $(TESTDIR)/UnitTest.o




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
