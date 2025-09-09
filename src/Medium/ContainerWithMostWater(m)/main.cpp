#include <iostream>
#include <vector>

int maxArea(std::vector<int>& height)
{
    int l = 0;
    int r = height.size() - 1;
    int max_water = 0;
    while(l < r)
    {
        int current_max = (r - l) * (height[l] <= height[r] ? height[l] : height[r]);
        if(current_max > max_water) max_water = current_max;
        if(height[l] > height[r]) r--;
        else l++;
    }
    return max_water;

    // Time Complexity: O(n)
    // Space Complexity: O(1)
}
int main()
{
    std::vector<int> height = {1,8,6,2,5,4,8,3,7};
    std::cout << maxArea(height) << "\n";
    return 0;
}
