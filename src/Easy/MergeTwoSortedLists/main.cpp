#include <iostream>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Time Complexity: O(n) where n is the number nodes across list1 and list2
// Space Complexity: O(1) - not counting the returned list
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
    ListNode* dummy = new ListNode();
    ListNode* result = dummy;

    while (list1 && list2)
    {
        if (list1->val <= list2->val)
        {
            result->next = list1;
            list1 = list1->next;
        }
        else
        {
            result->next = list2;
            list2 = list2->next;
        }
        result = result->next;
    }

    if (list1)
    {
        result->next = list1;
    }
    else
    {
        result->next = list2;
    }
    return dummy->next;
}

int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}