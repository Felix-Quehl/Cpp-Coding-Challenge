#include <iostream>
#include <world.h>
#include <cassert>

void test_message_is_correct()
{
    std::string expected = "Hello World & Hello Eleven!";
    std::string actual = world::getMessage("Eleven");
    assert(expected == actual);
}

int main()
{
    test_message_is_correct();
    std::cout << "all tests passed" << std::endl;
    return 0;
}