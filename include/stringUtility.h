#ifndef HEADER_StringUtility
#define HEADER_StringUtility

#include <iStringUtility.h>

namespace CodingChallenge
{
    class StringUtility : public IStringUtility
    {
    public:
        std::string interpolate(std::string *format, InterpolationPair *values, int count);
    };
}
#endif