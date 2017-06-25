
# chapter and compiler settings ------------------------------------------------

EXER_PREFIX := exer08_
TEST_PREFIX := test08_
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
executables := exer08_01 exer08_04 exer08_05_gen_sent exer08_05_xref

# names of the Bash test scripts
test_targets := $(sort $(basename $(wildcard $(TEST_PREFIX)*.sh) ) )

# names of the C++ unit tests
unit_tests := utest_lib_algs

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




# test rules not covered by implicit rules -------------------------------------

test08_05 : test08_05.sh exer08_05_gen_sent exer08_05_xref
	@printf test08_05.sh && ./test08_05.sh > /dev/null && printf ":    pass\n" \
		|| printf ":    ** test failure **\n"




# exercise build rules ---------------------------------------------------------

src := ../chap06

exer08_01.o : analy_refactor.h $(src)/student_info.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -I$(src) -c -o exer08_01.o exer08_01.cpp
exer08_01 : grade_check.o grade.o median.o student_info.o


exer08_05_gen_sent.o exer08_05_xref.o : override CPPFLAGS += -I../chap07
exer08_05_xref.o : override CXXFLAGS += -std=c++11

exer08_05_gen_sent.o : ../chap07/split.h
exer08_05_gen_sent : split.o

exer08_05_xref.o : ../chap07/split.h
exer08_05_xref : split.o

median.o : $(src)/median.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o median.o $(src)/median.cpp

grade.o : $(addprefix $(src)/, grade.cpp student_info.h grade.h median.h)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o grade.o $(src)/grade.cpp

grade_check.o : $(addprefix $(src)/, grade_check.cpp student_info.h)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o grade_check.o $(src)/grade_check.cpp

split.o : ../chap07/split.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o split.o ../chap07/split.cpp

student_info.o : $(src)/student_info.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o student_info.o $(src)/student_info.cpp


# unit testing build rules -----------------------------------------------------

# unit tests linked against CppUnit need to be compiled using the C++11
# standard, and the compiler needs to be informed where to find the header files
# and shared objects

utest_%.o : override CXXFLAGS += -std=c++11
utest_% : override LDFLAGS += -L$(LIBDIR) $(RPATH)
utest_% : override LDLIBS += -lcppunit

# unit tests for exercise 8-2 are of this form (with the exception of the unit
# test driver utest_lib_algs).  Unit tests for other exercises can overwrite
# this rule by creating their own.
utest_%.o : utest_%.h lib_algs.h

# build the list of library algorithm names from exercise 8-2
# alg_names := accumulate copy equal find search remove remove_copy transform partition
alg_names := copy equal find search remove remove_copy
utest_alg_names := $(addprefix utest_, $(alg_names))
utest_alg_names_h := $(addsuffix .h, $(utest_alg_names))
utest_alg_names_o := $(addsuffix .o, $(utest_alg_names))

# begin unit testing recipe section

utest_lib_algs.o : $(utest_alg_names_h)
utest_lib_algs : $(utest_alg_names_o)
