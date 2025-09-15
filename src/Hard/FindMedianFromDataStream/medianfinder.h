#ifndef MEDIANFINDER_H
#define MEDIANFINDER_H
#include <queue>
#include <algorithm>

class MedianFinder
{
public:
    MedianFinder();

    void addNum(int num);

    double findMedian();

private:
    std::priority_queue<int, std::greater<int>> small;
    std::priority_queue<int> large;
};



#endif //MEDIANFINDER_H
