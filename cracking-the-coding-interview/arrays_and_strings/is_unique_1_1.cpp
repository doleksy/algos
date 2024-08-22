//  is_unique_1_1.cpp
//
//  Implement an algorithm to determine is a string has all unique characters.
//  What if you cannot use additional data structures.

#include <gtest/gtest.h>

#include <string_view>
#include <unordered_set>


namespace
{

auto is_unique(std::string_view str) -> bool
{
    std::unordered_set<char> char_set;

    for (const auto c : str)
    {
        if (auto iter = char_set.find(c); iter == char_set.end())
        {
            char_set.insert(c);
        }
        else
        {
            // we found a match so the string is not unique
            return false;
        }
    }

    return true;
}

auto is_unique_ptr_way(const char *str) -> bool
{
    std::unordered_set<char> char_set;
    const char *pStr = str;
    while (*pStr != '\0')
    {
        if (auto iter = char_set.find(*pStr); iter == char_set.end())
        {
            char_set.insert(*pStr);
        }
        else
        {
            // we found a match so the string is not unique
            return false;
        }

        ++pStr;
    }

    return true;
}

}   // namespace

//////////////////////////////////////////////////////////


TEST(IsUnique, EmptyStringIsUnique)
{
    auto isUnique = is_unique("");
    EXPECT_TRUE(isUnique);
}

TEST(IsUnique, AIsUnique)
{
    auto isUnique = is_unique("a");
    EXPECT_TRUE(isUnique);
}

TEST(IsUnique, AAIsNotUnique)
{
    auto isUnique = is_unique("aa");
    EXPECT_FALSE(isUnique);
}

TEST(IsUnique, LongStringIsUnique)
{
    auto isUnique = is_unique("abcdefghijklmnop");
    EXPECT_TRUE(isUnique);
}

TEST(IsUnique, LongStringIsNotUnique)
{
    auto isUnique = is_unique("abcdefghijklmnopa");
    EXPECT_FALSE(isUnique);
}

//////////////////////////////////////////////////////////


TEST(IsUniquePtr, EmptyStringIsUnique)
{
    auto isUnique = is_unique_ptr_way("");
    EXPECT_TRUE(isUnique);
}

TEST(IsUniquePtr, AIsUnique)
{
    auto isUnique = is_unique_ptr_way("a");
    EXPECT_TRUE(isUnique);
}

TEST(IsUniquePtr, AAIsNotUnique)
{
    auto isUnique = is_unique_ptr_way("aa");
    EXPECT_FALSE(isUnique);
}

TEST(IsUniquePtr, LongStringIsUnique)
{
    auto isUnique = is_unique_ptr_way("abcdefghijklmnop");
    EXPECT_TRUE(isUnique);
}

TEST(IsUniquePtr, LongStringIsNotUnique)
{
    auto isUnique = is_unique_ptr_way("abcdefghijklmnopa");
    EXPECT_FALSE(isUnique);
}
