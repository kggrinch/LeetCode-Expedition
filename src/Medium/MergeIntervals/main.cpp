#include <iostream>
#include <vector>
#include <algorithm>

// Time Complexity: O(nlogn) where n = number of intervals
// Space Complexity: O(n) where n = number of intervals
std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals)
{
    std::sort(intervals.begin(), intervals.end()); // sort intervals by the first value
    std::vector<std::vector<int>> result;
    std::vector<int> current = intervals[0];
    for (int i = 1; i < intervals.size(); i++)
    {
        // If overlap
        if (intervals[i][0] <= current[1])
        {
            current[0] = std::min(current[0], intervals[i][0]);
            current[1] = std::max( current[1], intervals[i][1]);
        }
        else
        {
            result.push_back(current);
            current = intervals[i];
        }
    }
    result.push_back(current);
    return result;
}


int main()
{
    std::vector<std::vector<int>> intervals = {{1,3},{1,5},{6,7}};
    std::vector<std::vector<int>> result = merge(intervals);
    return 0;
}