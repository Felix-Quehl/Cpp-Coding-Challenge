#include <cstdarg>
#include <stringUtility.h>

namespace CodingChallenge
{
    /**
     *  @brief  Interpolates keys in a string with the given values.
     *  @param format  string that is holding the template for the interpolation.
     *  @param values  pointer to an array of type InterpolationPair[]
     *  @param count  number values on the array
     *  @return  Interpolated string
     *
     */
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
                position += value->value.length();
            }
        }
        return result;
    }
}