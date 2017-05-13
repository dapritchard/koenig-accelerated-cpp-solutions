# shell script fragment for testing framework
# declares arrays used to store test information


# declare testing variables ----------------------------------------------------

declare -a testname  # names of tests
declare -a input     # input to program
declare -a target    # target output

arr_idx=0            # current test index
