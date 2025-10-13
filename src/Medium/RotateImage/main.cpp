#include <iostream>
#include <vector>
#include <algorithm>

// Time Complexly: O(n^2)
// Space Complexity: O(1)
void rotate(std::vector<std::vector<int>>& matrix)
{
    int l = 0;
    int r = matrix[0].size() - 1;

    // Increment to inner rectangle
    while (l <= r)
    {
        // rotate n times
        for (int i = 0; i < r - l; i++)
        {
            int t = l;
            int b = r;

            int top_left = matrix[t][l + i];

            // Move bottom left to top left
            matrix[t][l + i] = matrix[b - i][l];

            // Move bottom right to bottom left
            matrix[b - i][l] = matrix[b][r - i];

            // Move top right to bottom right
            matrix[b][r - i] = matrix[t + i][r];

            // Move top left to top right
            matrix[t + i][r] = top_left;
        }
        l++;
        r--;
    }
}

void print_matrix(const std::vector<std::vector<int>>& matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main()
{
    std::vector<std::vector<int>> matrix =
    {
    {1,2,3},
    {4,5,6},
    {7,8,9},
    };
    std::cout << "Before:\n";
    print_matrix(matrix);

    rotate(matrix);

    std::cout << "\nAfter:\n";
    print_matrix(matrix);


    return 0;
}