//  check_permutation_1_2.cpp
//

#include <gtest/gtest.h>

#include <algorithm>
#include <string>


namespace
{

    auto check_permutation(std::string str1, std::string str2) -> bool
    {
        if (str1.size() != str2.size())
        {
            return false;
        }

        std::ranges::sort(str1);
        std::ranges::sort(str2);

        return (str1 == str2);
    }

}   // namespace

//////////////////////////////////////////////////////////


TEST(CheckPermutation, EmptyStringsArePermutations)
{
    auto is_permutation = check_permutation("", "");
    EXPECT_TRUE(is_permutation);
}

TEST(CheckPermutation, DifferentSizeStringsAreNotPermutations)
{
    auto is_permutation = check_permutation("aba", "abab");
    EXPECT_FALSE(is_permutation);
}

TEST(CheckPermutation, DifferentSizeStringsArePermutations)
{
    auto is_permutation = check_permutation("aba", "baa");
    EXPECT_TRUE(is_permutation);
}
