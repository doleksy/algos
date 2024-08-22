#include <iostream>
#include <string>
#include <vector>

// Apply backtracking on every element to search the required word
bool DepthFirstSearch(int row, int col, std::string word, int index, std::vector<std::vector<char>> &grid)
{

    if (word.length() == index)
    {
        return true;
    }
    // Check if this is a valid cell
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != word[index])
    {
        return false;
    }
    bool result = false;

    char temp = grid[row][col];
    grid[row][col] = '*';

    std::vector<std::vector<int>> offsets{ {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
    for (auto offset : offsets)
    {
        int rowOffset = offset[0];
        int colOffset = offset[1];
        result = DepthFirstSearch(row + rowOffset, col + colOffset, word, index + 1, grid);

        if (result)
        {
            break;
        }
    }

    grid[row][col] = temp;
    return result;
}

// Function to search a specific word in the grid
bool WordSearch(std::vector<std::vector<char>> grid, std::string word)
{
    for (int row = 0; row < grid.size(); row++)
    {
        for (int col = 0; col < grid[0].size(); col++)
        {
            if (DepthFirstSearch(row, col, word, 0, grid))
            {
                return true;
            }
        }
    }
    return false;
}


int main()
{
    std::vector<std::vector<std::vector<char>>> grid{
        {{'E', 'D', 'X', 'I', 'W'},
        {'P', 'U', 'F', 'M', 'Q'},
        {'I', 'C', 'Q', 'R', 'F'},
        {'M', 'A', 'L', 'C', 'A'},
        {'J', 'T', 'I', 'V', 'E'}},

        {{'E', 'D', 'X', 'I', 'W'},
        {'P', 'A', 'F', 'M', 'Q'},
        {'I', 'C', 'A', 'S', 'F'},
        {'M', 'A', 'L', 'C', 'A'},
        {'J', 'T', 'I', 'V', 'E'}},

        {{'h', 'e', 'c', 'm', 'l'},
        {'w', 'l', 'i', 'e', 'u'},
        {'a', 'r', 'r', 's', 'n'},
        {'s', 'i', 'i', 'o', 'r'}},

        {{'C', 'Q', 'N', 'A'},
        {'P', 'S', 'E', 'I'},
        {'Z', 'A', 'P', 'E'},
        {'J', 'V', 'T', 'K'}},

        {{'O', 'Y', 'O', 'I'},
        {'B', 'Y', 'N', 'M'},
        {'K', 'D', 'A', 'R'},
        {'C', 'I', 'M', 'I'},
        {'Z', 'I', 'T', 'O'}} };

    std::vector<std::string> word = { "EDUCATIVE", "PACANS", "warrior", "SAVE", "DYNAMIC" };

    for (int i = 0; i < word.size(); i++)
    {
        std::cout << i + 1 << ".\tGrid = " << std::endl;
//        PrintGrid(grid[i]);
        std::cout << "\tWord = " << word[i] << std::endl;
        auto search_result = WordSearch(grid[i], word[i]);
        std::cout << "\n\tSearch result = ";
        if (search_result)
            std::cout << "Word found" << std::endl;
        else
            std::cout << "Word couldn't be found" << std::endl;
        std::cout << std::string(96, '-') << "\n"
            << std::endl;
    }
}