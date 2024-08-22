
#include <gtest/gtest.h>

#include <cmath>

namespace
{
/*

Fast and Slow Pointers

https://www.educative.io/module/page/JZmo10C1Azw39ExQJ/10370001/4797540467474432/5118367033458688

Write an algorithm to determine if a number n is a happy number.

We use the following process to check if a given number is a happy number:

- Starting with the given number, replace the number with the sum of the squares of its digits.
- Repeat the process until:
  - The number equals 1, which will depict that the given number n is a happy number.
  - The number enters a cycle, which will depict that the given number n is not a happy number.

Return TRUE if n is a happy number, and FALSE if not.

Constraints
1 <= n <= 2^31−1

Example 1:
Input: n = 23
2^2 + 3^2 = 13
1^2 + 3^2 = 10
1^2 = 0^2 = 1
Output =true

Example 2:
Input: n = 2
2^2            = 4
4^2            = 16
1^2 + 6^2      = 37
3^2 + 7^2      = 58
5^2 + 8^2      = 89
8^2 + 9^2      = 145
1^2 + 4^2 +5^2 = 42
4^2 + 2^2      = 20
2^ + 0^        = 4  - loop
Output = false

*/

    int SumOfSquaredDigits(int number)
    {
        int totalSum = 0;
        while (number > 0)
        {
            int digit = number % 10;
            number = (number / 10);
            totalSum += digit * digit;
        }
        return totalSum;
    }

    bool IsHappyNumber(int n)
    {
        int slowPointer = n;
        int fastPointer = SumOfSquaredDigits(n);

        while ((slowPointer != fastPointer) and (fastPointer != 1))
        {
            slowPointer = SumOfSquaredDigits(slowPointer);
            fastPointer = SumOfSquaredDigits(SumOfSquaredDigits(fastPointer));
        }

        if (fastPointer == 1)
        {
            return true;
        }

        return false;
    }

}   // namespace

//////////////////////////////////////////////////////////


TEST(HappyNumber, Case2147483646)
{
    EXPECT_FALSE(IsHappyNumber(2147483646));
}

TEST(HappyNumber, Case1)
{
    EXPECT_TRUE(IsHappyNumber(1));
}

TEST(HappyNumber, Case19)
{
    EXPECT_TRUE(IsHappyNumber(19));
}

TEST(HappyNumber, Case8)
{
    EXPECT_FALSE(IsHappyNumber(8));
}

TEST(HappyNumber, Case7)
{
    EXPECT_TRUE(IsHappyNumber(7));
}
