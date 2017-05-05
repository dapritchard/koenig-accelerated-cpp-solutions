
# chapter and compiler settings ------------------------------------------------

EXER_PREFIX = exer00_
TEST_PREFIX = test00_

CXX = g++
CXXFLAGS = -Wall -g3




# create relevant variables ----------------------------------------------------

# names of the executables after stripping the .cpp suffix
executables := $(sort $(basename $(wildcard $(EXER_PREFIX)*.cpp) ) )

# names of the test scripts
test_targets := $(sort $(basename $(wildcard $(TEST_PREFIX)*.sh) ) )




# compilation rules section ----------------------------------------------------

.PHONY : all test $(TEST_PREFIX)% clean clobber

# default rule
all : $(executables)

# test compiled programs using test scripts.  Executables are included as
# prerequisites so as to insure that they exist before being invoked during
# testing.
test : $(test_targets) 

clean :
	rm -f *.o

clobber :
	rm -f *.o $(executables)




# build rules ------------------------------------------------------------------

# note: executables are built using implicit rules

# define implicit rule for testing.  The shell prints the test program name and
# executes the test.  If the test is successful then the "test pass" message is
# written and the OR statement is not evaluated.  If the test fails, then the
# last AND statement is not evaluated but the OR statement is, which writes a
# "test fail" message.
$(TEST_PREFIX)% : $(TEST_PREFIX)%.sh $(EXER_PREFIX)%
	@printf $< && ./$< > /dev/null && printf ":    pass\n" \
		|| printf ":    ** test failure **\n"
