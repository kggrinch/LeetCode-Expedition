#include <iostream>
#include <vector>


struct ListNode
{
    ListNode() : data(0), next(nullptr) {}
    ListNode(int new_data, ListNode* new_next) : data(new_data), next(new_next) {}
    int data;
    ListNode* next;
};

struct List
{
public:
    List() : head(nullptr) {}
    void createList(std::vector<int>& list)
    {
        ListNode* new_head = new ListNode(list[0], nullptr);
        ListNode* current = new_head;
        for(int i = 1; i < list.size(); i++)
        {
            ListNode* next_node = new ListNode(list[i], nullptr);
            current->next = next_node;
            current = current->next;
        }
        head = new_head;
    }
    ListNode* head;
};


// Brute Force
// Time Complexity:
// Space Complexity:
void swap(ListNode* item_after, ListNode* item_before, ListNode* item_pre)
{
    ListNode* temp = nullptr;
    temp = item_after->next;
    item_after->next = item_before;
    item_pre->next = item_after;
    item_before->next = temp;
}

void reorderList_BruteForce(ListNode* head)
{
    ListNode* current = head;
    ListNode* stop = nullptr; // stop pointer to keep track of when to stop flipping
    ListNode* flip_after = nullptr;
    ListNode* flip_before = nullptr;
    ListNode* stop_check = nullptr;

    // In a loop
    while(true)
    {
        // If flip2 = nullptr locate the tail and value before the tail
        if(flip_after == nullptr)
        {
            // Find value before the tail and set to flip1 and flip2
            // Note: Watch out for smaller lists where current->next->next causes an out of bounds error
            while(current->next != nullptr && current->next->next != nullptr && current->next->next->next != nullptr)
            {
                current = current->next;
            }
            if(current->next == nullptr || current->next->next == nullptr) return;
            stop_check = current; // set stop check
            flip_before = current->next; // set flip before (before last item)
            flip_after = current->next->next; // set flip after (last item)
            current = head; // restart current

            // Check if we stop
            if(flip_before == head || stop_check == stop || flip_after == stop || flip_before == stop)
            {
                if(stop == flip_after) return;

                stop = flip_after;
                flip_after = nullptr; // reset flip loop
                continue;
            }

            // If not stop swap flip items
            swap(flip_after, flip_before, stop_check);
            continue;
        }


        // Not null meaning we already did a swap
        // Save item before the tail and locate the next item before it
        // flip_after = flip_before; // Dont need this since they are already flipped
        flip_before = stop_check;
        while(current != nullptr && current->next != flip_before)
        {
            current = current->next;
        }
        if(current == nullptr) stop_check = flip_before;
        else stop_check = current;
        current = head;

        // Check if we stop
        if(flip_before == head || stop_check == stop || flip_after == stop || flip_before == stop)
        {
            stop = flip_after;
            flip_after = nullptr; // reset flip loop
            continue;
        }

        // If not stop swap flip items
        swap(flip_after, flip_before, stop_check);
    }
}

// Time Complexity: 6 + 2(n/2) = 6 + n = O(n)
// Space Complexity: 3 = O(1)
ListNode* find_center(ListNode* head)
{
    ListNode* slow = head; // 1 | 1
    ListNode* fast = head->next; // 1 | 1
    ListNode* result = nullptr; // 1 | 1
    while(fast != nullptr && fast->next != nullptr) // n / 2
    {
        fast = fast->next->next; // 1
        slow = slow->next; // 1
    }
    result = slow->next; // Save second half of the list // 1
    slow->next = nullptr; // Split the first half of the list from the second // 1
    return result; // 1
}

// Time Complexity: 4 + 4n = O(n)
// Space Complexity: 3 = O(1)
ListNode* reverse_list(ListNode* head)
{
    ListNode* prev = nullptr; // 1 | 1
    ListNode* current = head; // 1 | 1
    ListNode* next = nullptr; // 1 | 1
    while(current != nullptr) // n
    {
        next = current->next; // 1
        current->next = prev; // 1
        prev = current; // 1
        current = next; // 1
    }
    return prev; // 1
}

// Time Complexity: 3 + 6(n/2) = 3 + 3n = O(n)
// Space Complexity: 4 = O(1)
ListNode* merge_lists(ListNode* first, ListNode* second)
{
    ListNode* first_curr = first; // 1 | 1
    ListNode* second_curr = second; // 1 | 1
    while(second_curr != nullptr) // m = n / 2
    {
        ListNode* f_t = first_curr->next; // 1 | 1
        ListNode* s_t = second_curr->next; // 1 | 1

        first_curr->next = second_curr; // 1
        second_curr->next = f_t; // 1

        first_curr = f_t; // 1 | 1
        second_curr = s_t; // 1 | 1
    }
    return first; // 1
}

// Optimized Solution
// Time Complexity: 3n = O(n)
// Space Complexity: 2 = O(1)
void reorderList_Optimized(ListNode* head)
{
    // Find center node (head node of the second half of the list)
    ListNode* first = head; // 1 | 1
    ListNode* second = find_center(head); // O(n) | 1

    // Reverse second half of the list
    second = reverse_list(second); // O(n)

    // Merge first and second halves of the list
    first = merge_lists(first, second); // O(n)
}

void print_list(List list)
{
    ListNode* current = list.head;
    while(current != nullptr)
    {
        std::cout << current->data << ", ";
        current = current->next;
    }
}

int main()
{
    std::vector<int> items = {1,2,3,4,5};
    List l1;
    l1.createList(items);
    reorderList_Optimized(l1.head);

    print_list(l1);



    return 0;
}
