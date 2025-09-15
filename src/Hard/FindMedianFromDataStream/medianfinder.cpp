#include "medianfinder.h"

MedianFinder::MedianFinder() : small(), large()
{

}

void MedianFinder::addNum(int num)
{
    // Add to small heap
    small.push(num);

    // Check if small always holds values less than large
    if(!small.empty() && !large.empty() && small.top)

}

double MedianFinder::findMedian()
{

}