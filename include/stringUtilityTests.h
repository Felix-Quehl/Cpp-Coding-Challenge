#ifndef HEADER_StringUtilityTests
#define HEADER_StringUtilityTests

#include <string>
#include <stringUtility.h>

namespace CodingChallenge
{
    class StringUtilityTests
    {
    private:
        StringUtility setup_sut();

    public:
        void test_all();
        void test_polymorphism();
        void test_null_format();
        void test_interpolate_with_single_value();
        void test_interpolate_with_two_values();
        void test_interpolate_with_duplicate_values();
        void test_interpolate_with_extra_values();
        void test_interpolate_with_missing_values();
    };
}
#endif