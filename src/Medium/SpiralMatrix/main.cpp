#include <cstdint>
#include <iostream>
#include <vector>

// Time Complexity: O(n*m) where n = rows and m = columns
// Space Complexity: O(1)
std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix)
{
    std::vector<int> result;
    int l = 0;
    int r = matrix[0].size();
    int t = 0;
    int b = matrix.size();
    while (l < r && t < b)
    {
        // cover the top values (left to right) (top pointer)
        for (int i = t; i < r; ++i)
        {
            result.push_back(matrix[t][i]);
        }
        t++; // increment top to move it down

        // cover right values (top to bottom) (right pointer)
        for (int i = t; i < b; ++i)
        {
            result.push_back(matrix[i][r - 1]);
        }
        r--; // decrement right to move it left

        // Edge case handling
        // if l passed r of if t passed b then
        // the row or column we just left, and we don't need to go further down and can break.
        if (l >= r || t >= b) break;

        // cover bottom values (right to left) (bottom pointer)
        for (int i = r - 1; i >= l; --i)
        {
            result.push_back(matrix[b - 1][i]);
        }
        b--; // decrement bottom to move it up

        // cover left values (bottom to top) (left pointer)
        for (int i = b - 1; i >= t; --i)
        {
            result.push_back(matrix[i][l]);
        }
        l++; // increment left to move it right
    }
    return result;
}

int main()
{
    std::vector<std::vector<int>> matrix
    {
        {1},
        {2},
        {3},
        {4}
    };

    // {1,2,3,4}
    std::vector<int> result = spiralOrder(matrix);

    return 0;
}