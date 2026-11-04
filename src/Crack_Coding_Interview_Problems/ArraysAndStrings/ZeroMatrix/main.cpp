#include <iostream>
#include <vector>

// Problem - Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
//           column are set to 0.


// Important Notes
// 1. MxN matrix
// 2. row and column set to 0

// Questions
// 1. w

// Example:
//          1, 1, 0, 1, 1 | 0, 0, 0, 0, 0
//          1, 0, 1, 1, 1 | 0, 0, 0, 0, 0
//          1, 1, 1, 1, 1 | 1, 0, 0, 1, 1
//          1, 1, 1, 1, 1 | 1, 0, 0, 1, 1
//          1, 1, 1, 1, 1 | 1, 0, 0, 1, 1


// Solutions
// 1. Iterate through the matrix while saving the rows and columns to be nullified in arrays. Then nullify those rows and columns

// Optimal Solution
// 1. Iterate through the matrix while saving the rows and columns in the first row and column. Keep a bool to track if 0s exist in the first row and colum

void nullifyRow(std::vector<std::vector<int>>&  matrix, int row)
{
    for (int i = 0; i < matrix[row].size(); i++)
    {
        matrix[row][i] = 0;
    }
}

void nullifyColumn(std::vector<std::vector<int>>&  matrix, int column)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        matrix[i][column] = 0;
    }
}


// Solution 1
// Time Complexity: O(n x m)
// Space Complexity: O(n/m)
void zeroMatrix(std::vector<std::vector<int>>& matrix)
{
    // Keep track of which rows and columns have 0s
    std::vector<bool> rows(false, matrix.size());
    std::vector<bool> columns(false, matrix.size());

    // Store rows and columns with 0s
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                rows[i] = true;
                columns[j] = true;
            }
        }
    }

    // Nullify rows
    for (int i = 0; i < rows.size(); i++)
    {
        if (rows[i]) nullifyRow(matrix, i);
    }

    // Nullify Columns
    for (int i = 0; i < columns.size(); i++)
    {
        if (columns[i]) nullifyColumn(matrix, i);
    }
}

// Optimal Solution
// TC: O(n * m)
// SC: O(1)

void zeroMatrixOptimal(std::vector<std::vector<int>>& matrix)
{
    bool zeroExistsRow{};
    bool zeroExistsColumn{};

    // Check if 0s exist in the top row
    for (int i = 0; i < matrix[0].size(); i++)
    {
        if (matrix[0][i] == 0)
        {
            zeroExistsRow = true;
            break; // no need to check the rest if found one
        }
    }

    // Check if 0s exist in the left column
    for (int j = 0; j < matrix.size(); j++)
    {
        if (matrix[j][0] == 0)
        {
            zeroExistsColumn = true;
            break; // no need to check the rest if found one
        }
    }

    // Check the rest of the matrix for 0s skipping top row and left column
    for (int i = 1; i < matrix.size(); i++)
    {
        for (int j = 1; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[0][j] = 0; // convert top row index to 0
                matrix[i][0] = 0; // convert left column to 0
            }
        }
    }

    // Nullify rows
    for (int i = 0; i < matrix.size(); i++)
    {
        if (matrix[i][0] == 0) nullifyRow(matrix, i);
    }

    // Nullify Columns
    for (int j = 0; j < matrix[0].size(); j++)
    {
        if (matrix[0][j] == 0) nullifyColumn(matrix, j);
    }

    // Nullify top row if required
    if (zeroExistsRow) nullifyRow(matrix, 0);

    // Nullify left column if required
    if (zeroExistsColumn) nullifyColumn(matrix, 0);
}

int main()
{
    std::vector<std::vector<int>> matrix{
        {1, 1, 0, 1, 1},
          {1, 0, 1, 1, 1},
          {1, 1, 1, 1, 1},
          {1, 1, 1, 1, 1},
          {1, 1, 1, 1, 1},
        };
    zeroMatrixOptimal(matrix);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            std::cout << matrix[i][j] << ",";
        }
        std::cout << "\n";
    }

    return 0;
}