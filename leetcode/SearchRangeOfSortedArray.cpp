
#include <gtest/gtest.h>

#include <vector>


namespace
{
/*
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.


Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]


Constraints:

0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
nums is a non-decreasing array.
-10^9 <= target <= 10^9

*/

    std::vector<int> searchRange(std::vector<int> &nums, int target)
    {
        const int nNums = nums.size();
        int left = 0;
        int right = nNums - 1;

        std::vector output{ -1, -1 };

        // find first position
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                output[0] = mid;
                right = mid - 1;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        // If we found the first position...
        if (output[0] != -1)
        {
            // find last position
            left = output[0];
            right = nNums - 1;

            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (nums[mid] == target)
                {
                    output[1] = mid;
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }

        return output;
    }

}   // namespace

//////////////////////////////////////////////////////////

TEST(SearchRange, TestRangeFoundInMiddle)
{
    std::vector<int> nums{ 5,7,7,8,8,10 };

    std::vector<int> expectedOutput{ 3,4 };

    EXPECT_EQ(searchRange(nums, 8), expectedOutput);
}

TEST(SearchRange, TestRangeFoundAtStart)
{
    std::vector<int> nums{ 7,7,8,8,10,12 };

    std::vector<int> expectedOutput{ 0,1 };

    EXPECT_EQ(searchRange(nums, 7), expectedOutput);
}

TEST(SearchRange, TestRangeFoundAtEnd)
{
    std::vector<int> nums{ 5,7,7,8,8,10,10,10,10,10,10,10,10 };

    std::vector<int> expectedOutput{ 5,12 };

    EXPECT_EQ(searchRange(nums, 10), expectedOutput);
}

TEST(SearchRange, TestRangeNotFound)
{
    std::vector<int> nums{ 5,7,7,8,8,10,10,10,10,10,10,10,10 };

    std::vector<int> expectedOutput{ -1,-1 };

    EXPECT_EQ(searchRange(nums, 9), expectedOutput);
}

TEST(SearchRange, TestEmptyNums)
{
    std::vector<int> nums{ };

    std::vector<int> expectedOutput{ -1,-1 };

    EXPECT_EQ(searchRange(nums, 9), expectedOutput);
}
