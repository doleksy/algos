
#include <gtest/gtest.h>

#include <queue>

namespace
{
/*

Daily Coding Problem: Problem #??? [Easy]

This problem was asked by Google.

Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?

*/
    bool add_up_to_k(std::vector<int> nums, int k)
    {
        std::set<int> otherNums;
        for (int n : nums)
        {
            if (otherNums.count(n))
            {
                return true;
            }
            otherNums.insert(k - n);
        }
        return false;
    }

}   // namespace

//////////////////////////////////////////////////////////


TEST(AddUpToK, EmptyReturnsFalse)
{
    std::vector<int> testNums{ };

    EXPECT_FALSE(add_up_to_k(testNums, 42));
}

TEST(AddUpToK, Test1)
{
    std::vector<int> testNums{ 10, 15, 3, 7 };

    EXPECT_TRUE(add_up_to_k(testNums, 17));
}

TEST(AddUpToK, Test2)
{
    std::vector<int> testNums{ 10, 15, 3, 71 };

    EXPECT_FALSE(add_up_to_k(testNums, 17));
}
