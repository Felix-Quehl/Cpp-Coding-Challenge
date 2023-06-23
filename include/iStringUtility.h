#ifndef HEADER_IStringUtility
#define HEADER_IStringUtility

#include <string>

namespace CodingChallenge
{

    struct InterpolationPair
    {
        std::string key;
        std::string text;
    };

    class IStringUtility
    {
    public:
        virtual std::string interpolate(std::string *format, InterpolationPair *values, int count) = 0;
    };
}
#endif