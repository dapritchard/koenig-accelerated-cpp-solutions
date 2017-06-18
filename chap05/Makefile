
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

# names of the executables, obtained by stripping the .cpp suffix
#
# remove exer05_03.cpp from the list since that executable is not generated, and
# instead add exer05_03_vector and exer05_03_list (which are both built from
# exer05_03.cpp using different compiler defines directives).

executables := $(sort $(basename $(filter-out exer05_03.cpp,        \
                                   $(wildcard $(EXER_PREFIX)*.cpp)  \
                                     exer05_03_vector               \
                                     exer05_03_list)))

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




# test rules not covered by implicit rules -------------------------------------

test05_02 : test05_02.sh exer05_02_vector exer05_02_list
	@printf test05_02.sh && ./test05_02.sh > /dev/null && printf ":    pass\n" \
		|| printf ":    ** test failure **\n"

test05_03 : test05_03.sh exer05_03_vector exer05_03_list
	@printf test05_03.sh && ./test05_03.sh > /dev/null && printf ":    pass\n" \
		|| printf ":    ** test failure **\n"




# exercise build rules ---------------------------------------------------------

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

exer05_10.o : stream_ext_palind.h
exer05_10 : exer05_10.o stream_ext_palind.o

exer05_11.o : stream_ext_smallwd.h
exer05_11 : exer05_11.o stream_ext_smallwd.o

fails_vector.o : grade.h student_info.h

fails_vector_resize.o : grade.h student_info.h

fails_list.o : grade.h student_info.h

grade.o : student_info.h

rotations.o : rotations.h split.h

student_info.o : student_info.h




# unit testing build rules -----------------------------------------------------

# unit tests linked against CppUnit need to be compiled using the C++11
# standard, and the compiler needs to be informed where to find the header files
# and shared objects

utest_cxx11_o :=  utest_centered.o utest_extract_fails_resize.o utest_stream_ext_smallwd.o \
                  utest_stream_ext_palind.o utest_stream_upp_seg.o

utest_cxx11 := $(basename $(utest_cxx11_o))

$(utest_cxx11_o) : CXXFLAGS += -std=c++11
$(utest_cxx11) : LDFLAGS := -L$(LIBDIR) $(RPATH)
$(utest_cxx11) : LDLIBS := -lcppunit

# begin unit testing recipe section

utest_centered.o : centered_picture.h $(INCDIR)/cppunit/TestCase.h
utest_centered : utest_centered.o centered_picture.o

utest_concatenate.o : $(TESTDIR)/UnitTest.h rotations.h
utest_concatenate : utest_concatenate.o rotations.o split.o $(TESTDIR)/UnitTest.o

utest_extract_fails_resize.o : student_info.h
utest_extract_fails_resize : utest_extract_fails_resize.o fails_vector_resize.o grade.o median.o

utest_max_phrase_len.o : rotations.h $(TESTDIR)/UnitTest.h
utest_max_phrase_len : utest_max_phrase_len.o rotations.o split.o $(TESTDIR)/UnitTest.o

utest_rotations.o : rotations.h  $(TESTDIR)/UnitTest.h
utest_rotations : utest_rotations.o rotations.o split.o $(TESTDIR)/UnitTest.o

utest_stream_to_rotations.o : rotations.h $(TESTDIR)/UnitTest.h
utest_stream_to_rotations : utest_stream_to_rotations.o rotations.o split.o $(TESTDIR)/UnitTest.o

utest_stream_ext_smallwd.o : stream_ext_smallwd.h
utest_stream_ext_smallwd : stream_ext_smallwd.o

utest_stream_ext_palind.o : stream_ext_palind.h
utest_stream_ext_palind : stream_ext_palind.o

utest_stream_upp_seg.o : stream_upp_seg.h
utest_stream_upp_seg : stream_upp_seg.o

utest_string_to_lower.o : rotations.h $(TESTDIR)/UnitTest.h
utest_string_to_lower : utest_string_to_lower.o rotations.o split.o $(TESTDIR)/UnitTest.o
