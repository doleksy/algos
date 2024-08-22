#include <gtest/gtest.h>

#include <algorithm>


namespace
{
/*
 2.1  Insertion Sort

*/

    void insertion_sort(std::vector<int> &A)
    {
        const auto aSize = A.size();

        for (int i = 1; i < aSize; ++i)
        {
            const int key = A[i];

            int j = i - 1;
            while (j >= 0 and A[j] > key)
            {
                A[j + 1] = A[j];
                --j;
            }

            A[j + 1] = key;
        }
    }

}   // namespace

//////////////////////////////////////////////////////////


TEST(InsertionSort, EmptyReturnsEmpty)
{
    std::vector<int> inputArray{ };

    const std::vector<int> expectedArray{ };

    insertion_sort(inputArray);
    EXPECT_EQ(inputArray, expectedArray);
}

TEST(InsertionSort, SingleElement)
{
    std::vector<int> inputArray{ 42 };
    const std::vector<int> expectedArray{ 42 };

    insertion_sort(inputArray);
    EXPECT_EQ(inputArray, expectedArray);
}

TEST(InsertionSort, Test0)
{
    std::vector<int> inputArray{ 5,2,4,6,1,3 };

    std::vector<int> expectedArray(inputArray.size());
    std::partial_sort_copy(inputArray.cbegin(), inputArray.cend(),
                           expectedArray.begin(), expectedArray.end());

    insertion_sort(inputArray);
    EXPECT_EQ(inputArray, expectedArray);
}

TEST(InsertionSort, Test1)
{
    std::vector<int> inputArray{ 9, 8, 6, 7, 4, 5, 2, 0, 3, 1 };

    std::vector<int> expectedArray(inputArray.size());
    std::partial_sort_copy(inputArray.cbegin(), inputArray.cend(),
        expectedArray.begin(), expectedArray.end());

    insertion_sort(inputArray);
    EXPECT_EQ(inputArray, expectedArray);
}
