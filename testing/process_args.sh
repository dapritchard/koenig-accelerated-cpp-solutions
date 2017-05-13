# shell script fragment for testing framework
# processes command line arguments


# ensure an executable with name $exer_loc exists ------------------------------
if [[ ! -x "$exer_loc" ]]; then
    >&2 echo "error: no executable file $exer_loc exists"
    exit 1
fi




# set variable defaults --------------------------------------------------------

# default flag values
diff_bool=false
verbose_bool=false

# tracks whether all of the tests are successful; change to nonzero if any tests
# fail
exit_status=0




# parse command-line options ---------------------------------------------------

while getopts 'dhv' option; do

    case "$option" in

	d) diff_bool=true ;;

	h) echo "Options:"
	   echo "  -d    Print a diff between target and output strings"
	   echo "  -v    Print target and output strings"
	   exit 0
	   ;;

	v) verbose_bool=true ;;

	\?) exit 1 ;;
    esac
done
