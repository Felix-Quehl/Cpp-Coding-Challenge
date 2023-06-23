#include <iostream>
#include <cassert>

#include <stringUtilityTests.h>

int main()
{
    // If the coding challenge would not have been asking to implement in C++98,
    // I would have used Catch as a Testing Framework, but they are on later standards.
    // So I have swiftly thrown together some vanilla testing code.
    CodingChallenge::StringUtilityTests stringUtilityTests;
    stringUtilityTests.test_all();
    return 0;
}