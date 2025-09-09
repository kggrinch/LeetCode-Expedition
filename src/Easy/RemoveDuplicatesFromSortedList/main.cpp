#include <iostream>
#include "linkedList.h"

int main()
{
    LinkedList my_list;

    my_list.Insert(1);
    my_list.Insert(1);
    my_list.Insert(2);

    my_list.deleteDuplicates(my_list.get_head());

    return 0;

}
