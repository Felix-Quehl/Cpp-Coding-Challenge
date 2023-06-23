#include <cstdarg>
#include <stringUtility.h>

namespace CodingChallenge
{
    std::string StringUtility::interpolate(std::string *format, InterpolationPair *values, int count)
    {
        std::string result = format->c_str();
        while (count--)
        {
            InterpolationPair *value = values + count;
            std::string fullKey = "%(" + value->key + ")";
            int keyLength = fullKey.length();
            int position = 0;
            while ((position = result.find(fullKey, position)) >= 0)
            {
                result.erase(position, keyLength);
                result.insert(position, value->value);
                position+=value->value.length();
            }
        }
        return result;
    }
}