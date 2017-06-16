
# chapter and compiler settings ------------------------------------------------

EXER_PREFIX := exer05_
TEST_PREFIX := test05_
UNIT_PREFIX := utest_
RUN_PREFIX := run_
TESTDIR := ../testing
INCDIR := /usr/local/include
LIBDIR := /usr/local/lib
RPATH := -Wl,-rpath=$(LIBDIR)

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





# lower-level build rules ------------------------------------------------------

exer05_01.o : rotations.h
exer05_01 : exer05_01.o rotations.o split.o

exer05_02_list.o : grade.h student_info.h
exer05_02_list : exer05_02_list.o grade.o student_info.o fails_list.o median.o

exer05_02_vector.o : exer05_02_vector.cpp grade.h student_info.h
exer05_02_vector : exer05_02_vector.o grade.o student_info.o fails_vector.o median.o

exer05_03_list.o : grade.h student_info.h student_container.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -DLIST_CONTAINER_ -c -o exer05_03_list.o exer05_03.cpp
exer05_03_list : exer05_03_list.o grade.o student_info.o fails_list.o median.o

exer05_03_vector.o : grade.h student_info.h student_container.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o exer05_03_vector.o exer05_03.cpp
exer05_03_vector : exer05_03_vector.o grade.o student_info.o fails_vector.o median.o

exer05_05.o : centered_picture.h
exer05_05 : exer05_05.o centered_picture.o

exer05_06.o : grade.h student_info.h student_container.h
exer05_06 : exer05_06.o grade.o student_info.o fails_vector_resize.o median.o

exer05_09.o : stream_upp_seg.h
exer05_09 : exer05_09.o stream_upp_seg.o

fails_vector.o : grade.h student_info.h

fails_vector_resize.o : grade.h student_info.h

fails_list.o : grade.h student_info.h

grade.o : student_info.h

rotations.o : rotations.h split.h

student_info.o : student_info.h

utest_centered.o : CXXFLAGS += -std=c++11
utest_centered.o : centered_picture.h $(INCDIR)/cppunit/TestCase.h

utest_centered : LDFLAGS := -L$(LIBDIR) $(RPATH)
utest_centered : LDLIBS := -lcppunit
utest_centered : utest_centered.o centered_picture.o

utest_concatenate.o : $(TESTDIR)/UnitTest.h rotations.h
utest_concatenate : utest_concatenate.o rotations.o $(TESTDIR)/UnitTest.o

utest_extract_fails_resize.o : CXXFLAGS += -std=c++11
utest_extract_fails_resize.o : student_info.h

utest_extract_fails_resize : LDFLAGS := -L$(LIBDIR) $(RPATH)
utest_extract_fails_resize : LDLIBS := -lcppunit
utest_extract_fails_resize : utest_extract_fails_resize.o fails_vector_resize.o grade.o median.o

utest_max_phrase_len.o : rotations.h $(TESTDIR)/UnitTest.h
utest_max_phrase_len : utest_max_phrase_len.o rotations.o split.o $(TESTDIR)/UnitTest.o

utest_rotations.o : rotations.h  $(TESTDIR)/UnitTest.h
utest_rotations : utest_rotations.o rotations.o $(TESTDIR)/UnitTest.o

utest_stream_to_rotations.o : rotations.h $(TESTDIR)/UnitTest.h
utest_stream_to_rotations : utest_stream_to_rotations.o rotations.o split.o $(TESTDIR)/UnitTest.o

utest_stream_upp_seg.o : CXXFLAGS += -std=c++11
utest_stream_upp_seg.o : stream_upp_seg.h

utest_stream_upp_seg : LDFLAGS := -L$(LIBDIR) $(RPATH)
utest_stream_upp_seg : LDLIBS := -lcppunit
utest_stream_upp_seg : stream_upp_seg.o

utest_string_to_lower.o : rotations.h $(TESTDIR)/UnitTest.h
utest_string_to_lower : utest_string_to_lower.o rotations.o split.o $(TESTDIR)/UnitTest.o
