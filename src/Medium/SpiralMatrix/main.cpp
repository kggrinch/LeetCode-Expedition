#include <iostream>
#include <vector>

std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix)
{
    int c = matrix.size();
    int r = matrix[0].size();
    std::vector<int> result;
    std::vector<int> visited(c * r, -1);
    for (int i = 0; i < matrix.size(); i++)
    {
        // Read the left to right
        for (int j = 0; j < matrix[0].size(); j++)
        {
           int value = matrix[i][j];
           if (result[value] != -1)
           {
               visited[value] = value;
               result.push_back(value);
           }
        }
    }
}

int main()
{


    return 0;
}