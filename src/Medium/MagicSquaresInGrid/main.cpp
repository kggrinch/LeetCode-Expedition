#include <iostream>
#include <vector>

// Time Complexity: O(1)
// Space Complexity: O(1)
bool is_magic_square(const std::vector<std::vector<int>>& grid, int row, int column)
{
    // Check if 3x3 has all unique values and all the values are 9 <= x <= 1
    bool visited[10];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int number = grid[row + i][column + j];
            if (number < 1 || number > 9) return false;
            if (visited[number]) return false;
            visited[number] = true;
        }
    }

    // Check if both diagonal sums match
    int diagonal1 = grid[row][column] + grid[row + 1][column + 1] + grid[row + 2][column + 2];
    int diagonal2 = grid[row][column + 2] + grid[row + 1][column + 1] + grid[row + 2][column];
    if (diagonal1 != diagonal2) return false;

    // Check if rows sums match with each other and diagonals
    int row1 = grid[row][column] + grid[row][column + 1] + grid[row][column + 2];
    int row2 = grid[row + 1][column] + grid[row + 1][column + 1] + grid[row + 1][column + 2];
    int row3 = grid[row + 2][column] + grid[row + 2][column + 1] + grid[row + 2][column + 2];
    if (row1 != row2 || row1 != row3 || row2 != row3 || row1 != diagonal1) return false;

    // Check if columns sums match with each other and diagonals
    int column1 = grid[row][column] + grid[row + 1][column] + grid[row + 2][column];
    int column2 = grid[row][column + 1] + grid[row + 1][column + 1] + grid[row + 2][column + 1];
    int column3 = grid[row][column + 2] + grid[row + 1][column + 2] + grid[row + 2][column + 2];
    if (column1 != column2 || column1 != column3 || column2 != column3 || column1 != diagonal1) return false;

    // All requirements met return true
    return true;
}

// Time Complexity: O(cr) where r = number of rows & c = number of columns | O(cr) = (r-2)*(c-2) = rc-2r-2c-4
// Space Complexity: O(1)
int numMagicSquaresInside(std::vector<std::vector<int>>& grid)
{
    int result{};
    int row_length = grid.size();
    int column_length = grid[0].size();
    for (int row = 0; row + 2 < row_length; row++)
    {
        for (int column = 0; column + 2 < column_length; column++)
        {
            if (is_magic_square(grid, row, column)) result++; // O(1)
        }
    }
    return result;
}


int main()
{

}