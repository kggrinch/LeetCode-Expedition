#include <iostream>
#include "medianfinder.h"

int main()
{
    MedianFinder* obj = new MedianFinder();
    std::cout << "obj->addNum(-1) \n";
    obj->addNum(-1);

    std::cout << "findMedian: " << obj->findMedian() << "\n";

    std::cout << "obj->addNum(-2) \n";
    obj->addNum(-2);

    std::cout << "findMedian: " << obj->findMedian() << "\n";

    std::cout << "obj->addNum(-3) \n";
    obj->addNum(-3);

    std::cout << "findMedian: " << obj->findMedian() << "\n";

    std::cout << "obj->addNum(-4) \n";
    obj->addNum(-4);

    std::cout << "findMedian: " << obj->findMedian() << "\n";

    std::cout << "obj->addNum(-5) \n";
    obj->addNum(-5);

    std::cout << "findMedian: " << obj->findMedian() << "\n";

    return 0;
}
