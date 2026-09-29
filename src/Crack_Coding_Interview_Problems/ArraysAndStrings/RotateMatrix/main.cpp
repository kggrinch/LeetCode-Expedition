#include <iostream>
#include <vector>

// Problem - Given an image represented by an NxN matrix, where each pixel in the image is 4
//           bytes, write a method to rotate the image by 90 degrees. Can you do this in place?

// Important notes:
// 1. each pixel is 4 bytes
// 2. NxN matrix
// 3. Do in place
// 4. rotate 90 degrees

// Questions:
// 1. is each n out of the nxn spaces a byte?
// 2. are all pixel values inside the matrix unique

// Examples
// 1.   Original           | Rotated
//      [ 1   2   3   4 ]  | [ 13   9   5   1 ]
//      [ 5   6   7   8 ]  | [ 14   10  6   2 ]
//      [ 9  10  11  12 ]  | [ 15   11  7   3 ]
//      [13  14  15  16 ]  | [ 16   12  8   4 ]



// Solutions
// 1. rotate from the outer layer toward the inner layer (save each set layer in vector) | O(n^2) S(n)
// 2. rotate from the outer layer toward the inner layer (switch corners in reverse while saving the last corner) | O(n^2) S(1)

// Optimal Solution
// 1. Rotate starting with corners in reverse order saving the first one to temp var. Then move through each iteration in the layer the move into the inner layers

// Time Complexity: O(n^2)
// Space Complexity: S(1)
std::vector<std::vector<int>>& RotateMatrix(std::vector<std::vector<int>>& img)
{
    int l = 0;
    int r = img[0].size() - 1;
    while (l < r) // iterate through the layers
    {
        int t = l;
        int b = r; // nxn matrix so same length as r
        for (int i = 0; i < r - l; i++) // iterates through the indexes at each layer
        {
            int t_value = img[t][l + i];

            // top left = bottom left
            img[t][l + i] = img[b - i][l];

            // bottom left = bottom right
            img[b - i][l] = img[b][r - i];

            // bottom right = top right
            img[b][r - i] = img[t + i][r];

            // top right = top left
            img[t + i][r] = t_value;
        }
        l++;
        r--;
    }
    return img;
}

std::string run_matrix(const std::vector<std::vector<int>>& matrix)
{
    std::string s_result;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            s_result += std::to_string(matrix[i][j]) + ", ";
        }
        s_result += "\n";
    }
    return s_result;
}


bool compare(const std::vector<std::vector<int>>& expected, const std::vector<std::vector<int>>& result)
{
    return expected == result;
}

bool run_test(int test_num, const std::vector<std::vector<int>>& expected, const std::vector<std::vector<int>>& outcome)
{
    // if wrong
    if (!compare(expected, outcome))
    {
        std::cout << "Test: " << test_num << " Failed Expected: " << run_matrix(expected) << " Result: " << run_matrix(outcome) << "\n";
        return false;
    }
    std::cout << "Test: " << test_num << " Passed!!!\n";
    return true;
}

// Tests
bool test_simple()
{

    std::vector<std::vector<int>> m_1
    {{1, 2},
    {3, 4}
    };
    std::vector<std::vector<int>> r_1
    {{3, 1},
    {4, 2}
    };

    std::vector<std::vector<int>> m_2
    {{1,2,3},
    {4,5,6},
    {7,8,9}
    };

    std::vector<std::vector<int>> r_2
    {{7,4,1},
    {8,5,2},
    {9,6,3}
    };

    if (!run_test(0, r_1, RotateMatrix(m_1))) return false;
    if (!run_test(1, r_2, RotateMatrix(m_2))) return false;
    return true;
}

void run_test_suite()
{
    test_simple();
}


int main()
{
    run_test_suite();
}