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
//

// Time Complexity:
// Space Complexity:
std::vector<std::vector<int>>& RotateMatrix(std::vector<std::vector<int>>& img)
{
    int n = img.size();

    for (int layer = 0; layer < n / 2; layer++)
    {
        int first = layer;
        int last = n - 1 - layer;
        for (int i = first; i < last; i++)
        {
            int offset = i - first; // not sure about offset
            int top
        }
    }

}



int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}