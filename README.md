
## Solutions to Koenig and Moo's textbook _Accelerated C++_ ##

Solutions and related materials are organized into directories according to book
chapter.



### Solutions ###
	
  * Within a directory, exercises are named according to the scheme
    exerXX\_YY.ZZZ, where XX refers to the chapter number, YY refers to the
    exercise number, and the ZZZ refers to a file suffix.  So for example,
    exer00\_00.cpp is a C++ program written as a solution to chapter 0 
	exercise 0.
	  
  * Questions that do not require programming are answered as a text file with a
    .txt suffix.  So for example, exer00\_01.txt is a solution to chapter 0
    exercise 0 that is provided simply as an answer in a regular text format
    (i.e. there was no programming required for the exercise).




### Test programs ###

Programming exercises have accompanying test programs.

  * Testing programs are named according to the scheme testXX.YY.sh where XX
    refers to the chapter number and YY refers to the exercise number.
	  
  * Running the test program will output results from one or more tests as text
    to stdout.  The exit code of the program will be 0 if all of the tests were
    successful and nonzero if one or more tests fails.



	
### Makefiles ###

Makefiles are provided for each chapter to aid with compilation and testing
(with the exception of chapter 1 which did not include any programming
exercises).

  * To compile all of the programs in a directory, simply run **make** without any
    arguments while in the directory.
	  
  * To compile a single program, run make with the name of the exercise in the
    form exerXX\_YY as an argument while in the directory that the program is
    located.  So for example, running **make exer00\_00** will compile the
    program associated with chapter 0 exercise 0 and create an executable called
    exer00\_00.
	  
  * To test all of the programs in a directory, simply run **make test** while
    in the directory.  This will print a line of output for each program in the
    directory stating whether or not the program passed all of the tests created
    for it.
	  
  * To test a single program, you can run make with the name of the test program
    in the form testXX\_YY as an argument while in the directory that the
    program is located.  So for example, running **make test00\_00** will print
    a single line of output stating whether or not the program passed all of the
    tests created for it.
  
    Doing this essentially calls the appropriate test program and reports
    whether or not all of the tests in the program passed.  However, it
    suppresses all of the individual test information provided by the test
    program, so it may be preferable to run the corresponding test program
    directly instead.

  * To remove any object files in a directory created during the compilation
    process, simply run **make clean** while in the directory.
	
  * To remove both any object files and and executables in a directory created
    during the compilation process, simply run **make clobber** while in the
    directory.
