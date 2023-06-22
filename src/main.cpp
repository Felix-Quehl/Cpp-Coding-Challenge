#include <iostream>
#include <hello_world.h>
#include <cassert>

void test_message_is_correct()
{
    std::string expected = "Hello World & Hello Eleven!";
    std::string myName = "Eleven";
    Examples::HelloWorld helloWorld(myName);

    std::string actual = helloWorld.getMessage();
    assert(expected == actual);
}

int main()
{
    test_message_is_correct();
    std::cout << "all tests passed" << std::endl;
    return 0;
}