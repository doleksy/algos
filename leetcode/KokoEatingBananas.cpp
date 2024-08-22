
#include <gtest/gtest.h>

#include <cmath>
#include <vector>

namespace
{
/*
https://leetcode.com/problems/koko-eating-bananas/description/

Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
Return the minimum integer k such that she can eat all the bananas within h hours.


Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23


Constraints:

1 <= piles.length <= 10^4
piles.length <= h <= 10^9
1 <= piles[i] <= 10^9

*/

    bool canFinishEating(const std::vector<int> &piles, int h, int k)
    {
        long long totalTime{ 0 };

        for (auto p : piles)
        {
            totalTime += std::ceil(static_cast<double>(p) / k);
        }
        return totalTime <= h;
    }

    int minEatingSpeed(const std::vector<int> &piles, int h) {
        const int nPiles = piles.size();

        int left = 1;
        int right = 1'000'000'000;

        int minK = -1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (canFinishEating(piles, h, mid))
            {
                minK = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return minK;
    }

}   // namespace

//////////////////////////////////////////////////////////

TEST(MajorityElement, Piles4H8K4)
{
    const std::vector<int> piles{ 3, 6, 7, 11 };

    EXPECT_EQ(minEatingSpeed(piles, 8), 4);
}

TEST(MajorityElement, Piles5H5K30)
{
    const std::vector<int> piles{ 30, 11, 23, 4, 20 };

    EXPECT_EQ(minEatingSpeed(piles, 5), 30);
}

TEST(MajorityElement, Piles5H6K30)
{
    const std::vector<int> piles{ 30, 11, 23, 4, 20 };

    EXPECT_EQ(minEatingSpeed(piles, 6), 23);
}

TEST(MajorityElement, Piles1H312884469K2)
{
    const std::vector<int> piles{ 312884470 };

    EXPECT_EQ(minEatingSpeed(piles, 312884469), 2);
}

TEST(MajorityElement, Piles3H1000000000K3)
{
    const std::vector<int> piles{ 805306368, 805306368, 805306368 };

    EXPECT_EQ(minEatingSpeed(piles, 1000000000), 3);
}

TEST(MajorityElement, Piles3H1000000000K3v2)
{
    const std::vector<int> piles{ 1000000000, 1000000000, 1000000000 };

    EXPECT_EQ(minEatingSpeed(piles, 1000000000), 4);
}

TEST(MajorityElement, Piles1H1000000000K1)
{
    const std::vector<int> piles{ 1000000000 };

    EXPECT_EQ(minEatingSpeed(piles, 1000000000), 1);
}
