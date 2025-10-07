#include <iostream>
#include <vector>
#include <algorithm>

void rotate(std::vector<std::vector<int>>& matrix)
{
    int row = matrix.size();
    int column = matrix[0].size();
    int i = 0;
    int j = column;

    // Reverse each
    for (int i = 0; i < row; i++)
    {
       std::reverse(matrix[i].begin(), matrix[i].end());
    }


}

int main()
{
    return 0;
}