#include <iostream>
#include <vector>

// Problem - Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
//           column are set to 0.

// Important Notes
// 1. MxN matrix
// 2. row and column set to 0

// Questions
// 1. w

// Solutions
// 1. Iterate through the matrix convert row and column to zero. (save time by doing visited checks rxc checks S((nxm)/2)) | O(nxm)
// 2.

// Optimal Solution

// Time Complexity: O(m + n)
// Space Complexity: S(1)
bool convert(std::vector<std::vector<int>> matrix, int r, int c)
{
    int r_size = matrix.size();
    int c_size = matrix[r].size();

    // Converts the row
    for (int i = 0; i < r_size; i++)
    {
        if (matrix[r][i] != 0) matrix[r][i] = 0;
    }

    // Converts the col
    for (int i = 0; i < c_size; i++)
    {
        if (matrix[i][c] != 0) matrix[i][c] = 0;
    }

    return true;
}

std::vector<std::vector<int>> zeroMatrix(std::vector<std::vector<int>> matrix)
{

}






int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}