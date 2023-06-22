#ifndef HEADER_HELLO_WORLD
#define HEADER_HELLO_WORLD

#include <string>

namespace Examples
{
    class HelloWorld
    {
    private:
        std::string name;

    public:
        std::string getMessage();
        HelloWorld(std::string pName);
        ~HelloWorld() = default;
    };
}

#endif