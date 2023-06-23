#include <iostream>
#include <cassert>

#include <stringUtilityTests.h>
#include <stringUtility.h>

namespace CodingChallenge
{

    void StringUtilityTests::test_all()
    {
        std::cout << "Running tests ..." << std::endl;
        RUN_TEST(test_polymorphism);
        RUN_TEST(test_interpolate_with_single_value);
        RUN_TEST(test_interpolate_with_two_values);
        RUN_TEST(test_interpolate_with_duplicate_values);
        RUN_TEST(test_interpolate_with_extra_values);
        RUN_TEST(test_interpolate_with_missing_values);
        RUN_TEST(test_interpolate_with_tailing_replacement);
        RUN_TEST(test_interpolate_with_leading_replacement);
        std::cout << "...all tests passed" << std::endl;
    }

    void StringUtilityTests::test_polymorphism()
    {
        StringUtility sutImp = StringUtility();
        IStringUtility *sut = dynamic_cast<IStringUtility *>(&sutImp);
        assert(sut != NULL);
    }

    void StringUtilityTests::test_interpolate_with_single_value()
    {
        std::string expected = "The quick fox jumps over the lazy dog";
        StringUtility sut = StringUtility();

        std::string format = "The %(speed) fox jumps over the lazy dog";
        InterpolationPair values[] = {
            {"speed", "quick"},
        };
        std::string actual = sut.interpolate(&format, values, sizeof(values) / sizeof(InterpolationPair));

        assert(expected == actual);
    }

    void StringUtilityTests::test_interpolate_with_two_values()
    {
        std::string expected = "The quick brown fox jumps over the lazy dog";
        StringUtility sut = StringUtility();

        std::string format = "The %(speed) %(color) fox jumps over the lazy dog";
        InterpolationPair values[] = {
            {"speed", "quick"},
            {"color", "brown"},
        };
        std::string actual = sut.interpolate(&format, values, sizeof(values) / sizeof(InterpolationPair));

        assert(expected == actual);
    }

    void StringUtilityTests::test_interpolate_with_duplicate_values()
    {
        std::string expected = "The quick brown fox jumps over the lazy brown dog";
        StringUtility sut = StringUtility();

        std::string format = "The %(speed) %(color) fox jumps over the lazy %(color) dog";
        InterpolationPair values[] = {
            {"speed", "quick"},
            {"color", "brown"},
        };
        std::string actual = sut.interpolate(&format, values, sizeof(values) / sizeof(InterpolationPair));

        assert(expected == actual);
    }

    void StringUtilityTests::test_interpolate_with_extra_values()
    {
        std::string expected = "The quick brown fox jumps over the lazy brown dog";
        StringUtility sut = StringUtility();
        
        std::string format = "The %(speed) %(color) fox jumps over the lazy %(color) dog";
        InterpolationPair values[] = {
            {"speed", "quick"},
            {"color", "brown"},
            {"extra", "stuff"},
        };
        std::string actual = sut.interpolate(&format, values, sizeof(values) / sizeof(InterpolationPair));

        assert(expected == actual);
    }

    void StringUtilityTests::test_interpolate_with_missing_values()
    {
        std::string expected = "The quick brown %(missing) jumps over the lazy brown dog";
        StringUtility sut = StringUtility();

        std::string format = "The %(speed) %(color) %(missing) jumps over the lazy %(color) dog";
        InterpolationPair values[] = {
            {"speed", "quick"},
            {"color", "brown"},
            {"extra", "stuff"},
        };
        std::string actual = sut.interpolate(&format, values, sizeof(values) / sizeof(InterpolationPair));

        assert(expected == actual);
    }

    void StringUtilityTests::test_interpolate_with_tailing_replacement()
    {
        std::string expected = "The quick brown fox jumps over the lazy dogdog";
        StringUtility sut = StringUtility();

        std::string format = "The quick brown fox jumps over the lazy %(animal)%(animal)";
        InterpolationPair values[] = {
            {"animal", "dog"},
        };
        std::string actual = sut.interpolate(&format, values, sizeof(values) / sizeof(InterpolationPair));

        assert(expected == actual);
    }

    void StringUtilityTests::test_interpolate_with_leading_replacement()
    {
        std::string expected = "dogdog quick brown fox jumps over the lazy dog";
        StringUtility sut = StringUtility();

        std::string format = "%(animal)%(animal) quick brown fox jumps over the lazy dog";
        InterpolationPair values[] = {
            {"animal", "dog"},
        };
        std::string actual = sut.interpolate(&format, values, sizeof(values) / sizeof(InterpolationPair));

        assert(expected == actual);
    }
}