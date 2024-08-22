
#include <gtest/gtest.h>


namespace
{
/*

This problem was asked by Facebook.

Given a circular array, compute its maximum subarray sum in O(n) time. A subarray can be empty, and in this case the sum is 0.

For example, given [8, -1, 3, 4], return 15 as we choose the numbers 3, 4, and 8 where the 8 is obtained from wrapping around.

Given [-4, 5, 1, 0], return 6 as we choose the numbers 5 and 1.

A solution was found at: https://www.geeksforgeeks.org/maximum-contiguous-circular-sum/ using a modification of Kadane's Algorithm.

*/

    int max_sum_circular_subarray(std::vector<int> &circularArray)
    {
        const auto arraySize = circularArray.size();

        if (arraySize == 0)
        {
            return 0;
        }
        else if (arraySize == 1)
        {
            return circularArray[0];
        }

        int local_min{ };
        int global_min{ circularArray[0] };
        int local_max{ };
        int global_max{ circularArray[0] };
        int sum{ };

        for (int i : circularArray)
        {
            sum += i;

            local_min = std::min(local_min + i, i);
            global_min = std::min(global_min, local_min);

            local_max = std::max(local_max + i, i);
            global_max = std::max(global_max, local_max);
        }

        if (sum == global_min)
        {
            return global_max;
        }

        const int answer = std::max(global_max, sum - global_min);

        return answer;
    }

}   // namespace

//////////////////////////////////////////////////////////


TEST(MaxSumCircularSubarray, EmptyReturns0)
{
    std::vector<int> testArray{ };

    EXPECT_EQ(max_sum_circular_subarray(testArray), 0);
}

TEST(MaxSumCircularSubarray, SingleElementReturnsItself)
{
    std::vector<int> testArray{ 42 };

    EXPECT_EQ(max_sum_circular_subarray(testArray), 42);
}

TEST(MaxSumCircularSubarray, Test0)
{
    std::vector<int> testArray{ 8, -1, 3, 4 };  // 3, 4, 8 == 15

    EXPECT_EQ(max_sum_circular_subarray(testArray), 15);
}

TEST(MaxSumCircularSubarray, Test1)
{
    std::vector<int> testArray{ -4, 5, 1, 0 };  // 5, 1 == 6

    EXPECT_EQ(max_sum_circular_subarray(testArray), 6);
}

TEST(MaxSumCircularSubarray, Test2)
{
    std::vector<int> testArray{ 8, -8, 9, -9, 10, -11, 12 };  // 12, 8, -8, 9, -9, 10 == 22

    EXPECT_EQ(max_sum_circular_subarray(testArray), 22);
}

TEST(MaxSumCircularSubarray, Test3)
{
    std::vector<int> testArray{ 10, -3, -4, 7, 6, 5, -4, -1 };  // 7, 6, 5, -4, -1, 10 == 23

    EXPECT_EQ(max_sum_circular_subarray(testArray), 23);
}

TEST(MaxSumCircularSubarray, Test4)
{
    std::vector<int> testArray{ -1, 40, -14, 7, 6, 5, -4, -1 }; // 7, 6, 5, -4, -1, -1, 40 == 52

    EXPECT_EQ(max_sum_circular_subarray(testArray), 52);
}

TEST(MaxSumCircularSubarray, Test5)
{
    std::vector<int> testArray{ 1, -2, 3, -2 }; // 3 == 3

    EXPECT_EQ(max_sum_circular_subarray(testArray), 3);
}

TEST(MaxSumCircularSubarray, Test6)
{
    std::vector<int> testArray{ 5, -3, 5 }; // 5, 5 == 10

    EXPECT_EQ(max_sum_circular_subarray(testArray), 10);
}

TEST(MaxSumCircularSubarray, Test7)
{
    std::vector<int> testArray{ -3, -2, -3 }; // -2 == -2

    EXPECT_EQ(max_sum_circular_subarray(testArray), -2);
}
