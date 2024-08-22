
#include <gtest/gtest.h>

#include <vector>

namespace
{
/*

Given an array of size N, find the majority element. The majority element is the element that appears more than floor(N/2) times.
You may assume that the array is non-empty and the majority element always exist in the array.

Problem Constraints
1 <= |A| <= 106
1 <= Ai <= 109

Input Format
The first argument is an integer array A.

Output Format
Return the majority element.

Example Input
A = [2, 1, 2]

Example Output
2

Example Explanation
2 occurs 2 times which is greater than 3/2.
*/

int majorityElement(const std::vector<int> &A) {
        const int nInts = A.size();

        int currentPossible = A[0];
        int cnt = 1;

        for (int i = 1; i < nInts; ++i)
        {
            if (cnt == 0)
            {
                currentPossible = A[i];
                cnt = 1;
            }
            else
            {
                if (A[i] == currentPossible)
                {
                    ++cnt;
                }
                else
                {
                    --cnt;
                }
            }
        }

        return currentPossible;
    }

}   // namespace

//////////////////////////////////////////////////////////

TEST(MajorityElement, MajorityIs1)
{
    const std::vector<int> A{ 1, 2, 1, 1, 2, 3, 1 };

    EXPECT_EQ(majorityElement(A), 1);
}

TEST(MajorityElement, MajorityIs2)
{
    const std::vector<int> A{ 2, 1, 2 };

    EXPECT_EQ(majorityElement(A), 2);
}
