
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

    bool isSingleToTheLeft(std::vector<int> &nums, int index)
    {
        if (index == nums.size() - 1)
        {
            return true;
        }

        if (index % 2)  // odd
        {
            return nums[index] != nums[index - 1];
        }
        else    // even
        {
            return nums[index] != nums[index + 1];
        }
    }

    int singleNonDuplicate(std::vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;

        int element = -1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (isSingleToTheLeft(nums, mid))
            {
                element = nums[mid];
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return element;
    }

}   // namespace

//////////////////////////////////////////////////////////

TEST(SingleElement, TestFoundTowardsLeft)
{
    std::vector<int> nums{ 1,1,2,3,3,4,4,8,8 };

    EXPECT_EQ(singleNonDuplicate(nums), 2);
}

TEST(SingleElement, TestFoundInMiddle)
{
    std::vector<int> nums{ 3,3,7,7,10,11,11 };

    EXPECT_EQ(singleNonDuplicate(nums), 10);
}

TEST(SingleElement, TestFoundAtStart)
{
    std::vector<int> nums{ 2,3,3,7,7,11,11 };

    EXPECT_EQ(singleNonDuplicate(nums), 2);
}

TEST(SingleElement, TestFoundAtEnd)
{
    std::vector<int> nums{ 3,3,7,7,10,10,11,11,42 };

    EXPECT_EQ(singleNonDuplicate(nums), 42);
}
