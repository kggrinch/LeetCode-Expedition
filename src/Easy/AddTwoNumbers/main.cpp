#include <iostream>

#include "linkedList.h"

int main()
{
    LinkedList l1, l2, l3;

    l1.Insert(8);
    l1.Insert(3);
    l1.Insert(2);

    l2.Insert(9);
    l2.Insert(2);
    l2.Insert(1);

    l3.addTwoNumbers(l1.get_head(), l2.get_head());

    return 0;
}
