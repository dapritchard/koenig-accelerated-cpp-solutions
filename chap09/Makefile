
# chapter and compiler settings ------------------------------------------------

EXER_PREFIX := exer09_
TEST_PREFIX := test09_
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

src := ../chap06
exer09_01.o grade.o median.o : override CPPFLAGS += -I$(src)

exer09_01.o : grade.h $(src)/median.h student_info.h
exer09_01 : grade.o median.o student_info.o

exer09_03.o : grade.h $(src)/median.h student_info.h
exer09_03 : grade.o median.o student_info.o

exer09_04.o : grade.h $(src)/median.h student_info.h
exer09_04 : grade.o median.o student_info.o

exer09_05.o : pf_student_info.h
exer09_05 : pf_student_info.o

exer09_06.o : pf_student_info.h extract_vec_if.h
exer09_06 : pf_student_info.o

grade.o : $(src)/median.h student_info.h

median.o : $(src)/median.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o median.o $(src)/median.cpp

pf_student_info.o : pf_student_info.h

student_info.o : student_info.h




# # unit testing build rules -----------------------------------------------------

# unit tests linked against CppUnit need to be compiled using the C++11
# standard, and the compiler needs to be informed where to find the header files
# and shared objects

utest_%.o : override CXXFLAGS += -std=c++11
utest_% : override LDFLAGS += -L$(LIBDIR) $(RPATH)
utest_% : override LDLIBS += -lcppunit

# # begin unit testing recipe section

# utest_gen_sentence.o : gen_sentence.h split.h nrand.h
# utest_gen_sentence : gen_sentence.o split.o nrand.o
