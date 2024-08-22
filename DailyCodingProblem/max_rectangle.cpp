
#include <gtest/gtest.h>

#include <queue>

namespace
{
/*

Daily Coding Problem: Problem #870 [Medium]

This question was asked by Google.

Given an N by M matrix consisting only of 1's and 0's, find the largest rectangle containing only 1's and return its area.

For example, given the following matrix:

[[1, 0, 0, 0],
 [1, 0, 1, 1],
 [1, 0, 1, 1],
 [0, 1, 0, 0]]

Return 4.
*/
    int measure_rectangle(std::vector<std::vector<int>> &matrix, int inX, int inY, std::queue<std::pair<int, int>> nodes)
    {
        const int height = matrix.size();
        if (height == 0) return -1;

        const int width = matrix[0].size();

        nodes.push({ inX, inY });

        int rectSize{ 0 };

        while (!nodes.empty())
        {
            const auto [x, y] = nodes.front();
            nodes.pop();

            if (x >= 0 and y >= 0 and x < width and y < height and matrix[y][x] == 1)
            {
                nodes.push({ x + 1, y    });
                nodes.push({ x - 1, y    });
                nodes.push({ x    , y + 1});
                nodes.push({ x    , y - 1});

                matrix[y][x] = 0;
                ++rectSize;
            }
        }

        return rectSize;
    }

    int max_rectangle(std::vector<std::vector<int>> &matrix)
    {
        const int height = matrix.size();
        if (height == 0) return -1;

        const int width = matrix[0].size();

        std::queue<std::pair<int, int>> nodes;
        int maxRect{ -1 };

        for (int y = 0; y < height; ++y)
        {
            for (int x = 0; x < width; ++x)
            {
                if (matrix[y][x] == 1)
                {
                    int rectSize = measure_rectangle(matrix, x, y, nodes);
                    maxRect = std::max(maxRect, rectSize);
                }
            }
        }

        return maxRect;
    }

}   // namespace

//////////////////////////////////////////////////////////


TEST(MaxRectangle, EmptyReturnsMinus1)
{
    std::vector<std::vector<int>> testArray{ };

    EXPECT_EQ(max_rectangle(testArray), -1);
}

TEST(MaxRectangle, TestFromEmail)
{
    std::vector<std::vector<int>> testArray
    {
        {1, 0, 0, 0},
        {1, 0, 1, 1},
        {1, 0, 1, 1},
        {0, 1, 0, 0}
    };

    EXPECT_EQ(max_rectangle(testArray), 4);
}

TEST(MaxRectangle, Test2)
{
    std::vector<std::vector<int>> testArray
    {
        {1, 0, 0, 0},
        {1, 0, 1, 0},
        {1, 0, 1, 1},
        {0, 1, 0, 0}
    };

    EXPECT_EQ(max_rectangle(testArray), 3);
}

TEST(MaxRectangle, Test3)
{
    std::vector<std::vector<int>> testArray
    {
        {1, 0, 0, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 0, 0}
    };

    EXPECT_EQ(max_rectangle(testArray), 6);
}

