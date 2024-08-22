#include <iostream>
#include <string>
#include <vector>
#include <stack>

bool IsValidPlacement(int rowToCheck, int colToCheck, std::vector<int> &solution)
{
    int row{};
    int col{};
    int diagonalOffset{ 0 };

    // check all prior rows and columns for a queen
    for (int i = 0; i < rowToCheck; ++i)
    {
        row = i;
        col = solution[row];
        diagonalOffset = rowToCheck - row;

        if ((colToCheck == col)
            || (colToCheck - diagonalOffset == col)
            || (colToCheck + diagonalOffset == col))
        {
            return false;
        }
    }

    return true;
}

int SolveNQueens(int n)
{
    std::vector<int> solution(n);
    std::stack<int> columnStack;
    int nSolutions{ 0 };

    int row{ 0 };
    int col{ 0 };

    while (row < n)
    {
        // check if a queen can be placed in any column of this row
        while (col < n)
        {
            if (IsValidPlacement(row, col, solution))
            {
                columnStack.push(col);
                solution[row] = col;

                // found a queen placement for this row, check next one
                // and reset column
                ++row;
                col = 0;
                break;
            }
            ++col;
        }

        // If we have checked all of the columns...
        // NOTE: col will only == n if we did not find a valid placement
        // for this row, otherwise col will be at most n-1 because we would
        // have broken out of the col loop before incrementing col the final
        // time
        if (col == n)
        {
            // If there are possible columns on the stack...
            if (!columnStack.empty())
            {
                // back up one row...
                --row;
                // and go to the next column
                col = columnStack.top() + 1;
                columnStack.pop();
            }
            else
            {
                // we have exhausted all possibilities
                break;
            }
        }

        // check for a solution
        if (row == n)
        {
            // We found a solution...
            ++nSolutions;
            // so, back up one row and go to the next column
            // to check for more solutions
            --row;
            col = columnStack.top() + 1;
            columnStack.pop();
        }
    }

    return nSolutions;
}

int main() {
    std::vector<int> n = { 4, 5, 6, 7, 8 };

    for (int i : n) {
        std::vector<std::vector<int>> results;
        int res = SolveNQueens(i);
        std::cout << i - 3 << ". Total solution count for " << i << " queens on the chessboard ("
            << i << "x" << i << "): " << res << std::endl;
        std::cout << std::string(100, '-') << std::endl;
    }
}