# C++ Coding Challenge

**Test Execution Status**  
[![build_and_test](https://github.com/Felix-Quehl/cpp_playground/actions/workflows/c-cpp.yml/badge.svg)](https://github.com/Felix-Quehl/cpp_playground/actions/workflows/c-cpp.yml)

This is my rather quick implementation of the coding challenge below. It features:

* Make File to build the code from console
* Unite Tests
* GitHub Action CI Pipeline

```bash
----8<----8<----8<----8<----8<----8<----8<----8<----8<----8<----8<----8<----8<----

        Specify and implement an interface to interpolate variables into
        a format string.  In the format string, variables are represented
        by a percentage sign followed by a variable name in parentheses.

        The interpolation interface needs only support string variables.

        The code must be valid C++98 (!) and compile without additional
        library dependencies besides the STL.

        Example:

        Given the variables

          adj = "quick"
          color = "brown"

        and the format string

          "The %(adj) %(color) fox jumps over the lazy dog"

        the result after interpolation should be

          "The quick brown fox jumps over the lazy dog"

---->8---->8---->8---->8---->8---->8---->8---->8---->8---->8---->8---->8---->8----
```

## How to Run

*Notice: I am developed this on linux/ubuntu, in theory the code should run fine on windows but I have not checked that. What probably need to be changed slightly are some path in the Makefile.*

**compile a clean and run the tests**

```bash
make clean test
```

*Example Output:*

```bash
rm -rf ./src/main.o ./src/stringUtilityTests.o ./src/stringUtility.o a.out
g++ -std=c++98 -Wall -Wextra -pedantic -I./include  -I./include -o src/stringUtilityTests.o -c src/stringUtilityTests.cpp 
g++ -std=c++98 -Wall -Wextra -pedantic -I./include  -I./include -o src/main.o -c src/main.cpp 
g++ -std=c++98 -Wall -Wextra -pedantic -I./include  -I./include -o src/stringUtility.o -c src/stringUtility.cpp 
g++  src/stringUtilityTests.o src/main.o src/stringUtility.o -o a.out
./a.out
Running tests ...
Test-Case : test_polymorphism                           :       Pass
Test-Case : test_interpolate_with_single_value          :       Pass
Test-Case : test_interpolate_with_two_values            :       Pass
Test-Case : test_interpolate_with_duplicate_values      :       Pass
Test-Case : test_interpolate_with_extra_values          :       Pass
Test-Case : test_interpolate_with_missing_values        :       Pass
...all tests passed
```
