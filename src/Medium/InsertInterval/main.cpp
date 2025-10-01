#include <iostream>
#include <vector>

std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval)
{
    std::vector<std::vector<int>> result;
    for (int i = 0; i < intervals.size(); ++i)
    {
        if (newInterval[1] < intervals[i][0]) result.push_back(newInterval);
        else if (newInterval[0] > intervals[i][1]) result.push_back(newInterval);
        else
        {
            newInterval[0] = std::min(newInterval[0], intervals[i][0]);
            newInterval[1] = std::max(newInterval[1], intervals[i][1]);
        }
    }
    result.push_back(newInterval);
    return result;
}

int main()
{
    std::vector<std::vector<int>> intervals = {{1,3}, {6,9}};
    std::vector<int> newInterval = {2, 5};
    std::vector<std::vector<int>> result = insert(intervals, newInterval);
    return 0;
}