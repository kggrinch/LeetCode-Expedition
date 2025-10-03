#include <iostream>
#include <vector>

// Time Complexity: O(n) where n = each index pair
// Space Complexity: O(n) where n = each index pair
std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval)
{
    std::vector<std::vector<int>> result; // build result
    if (intervals.empty()) {result.push_back(newInterval); return result;} // if interval empty return new interval
    // Iterate through each interval index
    for (int i = 0; i < intervals.size(); ++i)
    {
        // If newIntervals max value is less than current intervals lowest value
        // place new interval in result and update new interval to be the current interval index
        if (newInterval[1] < intervals[i][0])
        {
            result.push_back(newInterval);
            newInterval = intervals[i];
        }
        // If newIntervals the lowest value is greater than current intervals greatest value
        // place current interval in results and continue to next interval index
        else if (newInterval[0] > intervals[i][1]) result.push_back(intervals[i]);
        // If newInterval merges with current interval then update the new interval
        // between the lowest and largest values in both and continue to next interval
        else
        {
            newInterval[0] = std::min(newInterval[0], intervals[i][0]);
            newInterval[1] = std::max(newInterval[1], intervals[i][1]);
        }
    }
    // After the loop ends the newInterval will contain interval that belongs at the end of the list.
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