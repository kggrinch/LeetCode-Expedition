#include <iostream>
#include <vector>
#include <unordered_map>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Brute Force
// Time Complexity: O(n * k) where n = size of the list | k = number of lists
// Space Complexity: O(n)
ListNode* mergeKLists(std::vector<ListNode*>& lists)
{
    int n = lists.size();

    // Check if array is empty
    if (lists.empty()) return nullptr;

    // std::vector<std::pair<bool, ListNode*>> indexes(n); // Might not need the bool can just check manually if nullptr
    std::vector<ListNode*> indexes(n);
    for (int i = 0; i < lists.size(); ++i)
    {
        indexes[i] = lists[i];
    }

    ListNode* result = new ListNode;
    ListNode* merged = result;

    bool run = true;
    while (run)
    {
        // Create array to hold all current index values of the lists
        std::vector<ListNode*> values;
        for (int i = 0; i < lists.size(); ++i)
        {
            // If the lists is not at the end then add it into the values
            if (indexes[i] != nullptr) values.push_back(indexes[i]);
        }

        // edge case to handle empty lists in vector
        if (values.empty()) break;

        // run through all the retrieved current index values from the lists
        // and find the min value insert it into the result and increment the list that has the min value
        int min = INT_MAX;
        ListNode* smallest_list = nullptr;
        for (ListNode* c : values)
        {
            if (c->val < min)
            {
                min = c->val;
                smallest_list = c;
            }
        }
        result->next = smallest_list;
        result = result->next;

        // Increment the list with the min value
        for (int i = 0; i < indexes.size(); ++i)
        {
            if (indexes[i] == smallest_list) indexes[i] = indexes[i]->next;
        }

        // Check if all lists reached the end
        int all_end = true;
        for (int i = 0; i < lists.size(); ++i)
        {
            if (indexes[i] != nullptr)
            {
                all_end = false;
                break;
            }
        }
        if (all_end) run = false;
    }
    return merged->next;
}



int main()
{
    // List 1
    ListNode list1_v3(4);
    ListNode list1_v2(2, &list1_v3);
    ListNode list1_v1(1, &list1_v2);

    // List 2
    ListNode list2_v3(5);
    ListNode list2_v2(3, &list2_v3);
    ListNode list2_v1(1, &list2_v2);

    // List 3
    ListNode list3_v3(6);
    ListNode list3_v2(3, &list3_v3);

    std::vector<ListNode*> lists = {&list1_v1, &list2_v1, &list3_v2};
    std::vector<ListNode*> empty_vector;

    std::vector<ListNode*> vector_w_empty_list = {nullptr, nullptr};

    ListNode* result = mergeKLists(vector_w_empty_list);
    return 0;
}