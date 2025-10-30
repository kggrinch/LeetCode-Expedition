#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// Brute Force
// Time Complexity: O(n)
// Space Complexity: O(1)
ListNode* removeNthFromEnd(ListNode* head, int n)
{
    int end{};
    int index{};

    // Get the size of the list
    ListNode* current = head;
    while (current != nullptr)
    {
        end++;
        current = current->next;
    }

    // Find node n from end
    current = head;
    ListNode* prev = nullptr; // hold node before the remove node
    while (index != (end - n))
    {
        index++;
        prev = current;
        current = current->next;
    }

    // check if remove node is head
    if (prev == nullptr)
    {
        head = head->next;
        current->next = current->next;
        current = nullptr;
        return head;
    }

    // remove node
    prev->next = current->next;
    current->next = nullptr;
    current = nullptr;
    return head;
}



// Dummy Node Approach
// Time Complexity: O(n)
// Space Complexity: O(1)
ListNode* removeNthFromEnd_v2(ListNode* head, int n)
{
    // dummy node to offset traversal to find the node before the remove_node
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    int size{};

    // Get the size of the list
    ListNode* current = head;
    while (current != nullptr)
    {
        size++;
        current = current->next;
    }

    current = dummy;
    for (int i = 0; i < size - n; ++i)
    {
        current = current->next;
    }

    ListNode* remove_node = current->next;
    current->next = remove_node->next;
    head = dummy->next;
    delete dummy;
    return head;
}

// Optimal Solution - traverse list once
// Time Complexity: O(n)
// Space Complexity: O(1)
ListNode* removeNthFromEnd_optimal(ListNode* head, int n)
{
    // Strategy -
    // dummy node - Use a dummy node attached to the head to find the node before the remove node.
    // fast and slow - offset the distance between the fast and slow pointers to be n away from each other. Then
    //                 traverse the list until fast reached the end which will put slow at the node before the remove node.


    // dummy node to offset traversal to find the node before the remove_node
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* fast = dummy;
    ListNode* slow = dummy;

    // Move fast to n+1 steps (+1 because of the offset on dummy node)
    for (int i = 0; i <= n; ++i)
    {
        fast = fast->next;
    }

    // Traverse list until fast reaches the end
    // At this point slow->next should be n steps away from fast which is at the end
    // Slow right now is the node before the remove_node
    while (fast)
    {
        fast = fast->next;
        slow = slow->next;
    }

    // remove node
    ListNode* remove_node = slow->next;
    slow->next = remove_node->next;
    head = dummy->next;
    delete dummy;
    return head;
}





int main()
{
    ListNode node1(2);
    ListNode head(1, &node1);
    ListNode* result = removeNthFromEnd(&head, 1);

    return 0;
}