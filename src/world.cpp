#include <hello_world.h>

Examples::HelloWorld::HelloWorld(std::string pName): name(pName)
{
   
}

std::string Examples::HelloWorld::getMessage()
{
    return "Hello World & Hello " + name + "!";
}