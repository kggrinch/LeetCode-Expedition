#include "medianfinder.h"

MedianFinder::MedianFinder() : small(), large() {}

// Time Complexity: log(n)
// Space Complexity: O(1)
void MedianFinder::addNum(int num)
{
    // Add to small heap
    small.push(num);

    // Check if small always holds values less than large
    if(!small.empty() && !large.empty() && small.top() > large.top())
    {
        // remove the max value in small and place it into large
        small.pop();
        large.push(num);
    }

    // Check if the size difference is always 1 apart
    // Check if small holds more elements then large
    if(small.size() > large.size() + 1)
    {
        // remove the max value in small and place it into large
        int popped_value = small.top();
        small.pop();
        large.push(popped_value);
    }
    // Check if large holds more elements then small
    if(large.size() > small.size() + 1)
    {
        // remove the max value in small and place it into large
        int popped_value = large.top();
        large.pop();
        small.push(popped_value);
    }
}

// Time Complexity: O(1)
// Space Complexity: O(1)
double MedianFinder::findMedian()
{
    // if odd
    if(large.size() > small.size()) return large.top();
    if(small.size() > large.size())return small.top();

    // if even return mean
    double small_val = small.top(); // - cast into double
    double large_val = large.top();
    return (small_val + large_val) / 2;
}