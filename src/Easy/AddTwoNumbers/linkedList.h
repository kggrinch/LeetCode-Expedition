#ifndef LIST_H_
#define LIST_H_


struct ListNode
{
    int val;
    ListNode* next;
};

class LinkedList
{
public:
    LinkedList();

    bool Insert(int value);

    ListNode* deleteDuplicates(ListNode* head);

    bool isDup(int value, ListNode* list1);

    ListNode* get_head();

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);


private:
    ListNode* head;

};



#endif
