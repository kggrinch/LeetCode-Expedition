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
    std::priority_queue<int> small; // Smallest max heap
    std::priority_queue<int, std::vector<int>, std::greater<int>> large; // Largest min heap
};



#endif //MEDIANFINDER_H
