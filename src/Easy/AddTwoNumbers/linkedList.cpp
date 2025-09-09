#include "linkedList.h"
#include <iostream>
#include <string>
#include <algorithm>


LinkedList::LinkedList() : head(nullptr)
{

}


bool LinkedList::Insert(int value)
{
  // Allocate new memory for node. Insert copied object into new allocated node
  ListNode* new_node = new ListNode;
  new_node->val = value;
  new_node->next = nullptr;

  // Check if list is empty. Assign head to insert_node
  if(head == nullptr)
  {
    head = new_node;
    return true;
  }

  // Check if insert_node is to be inserted first in the list
  // if(new_node->val < head->val)
  // {
  //   new_node->next = head;
  //   head = new_node;
  //   return true;
  // }

  // Traverse list for correct position. Return true.
  ListNode* current = head;
  while(current->next != nullptr)
  {
    current = current->next;
  }
  new_node->next = current->next;
  current->next = new_node;
  return true;

}



// LeetCode problem here.
// Brute force solution
// Optimized solution - trick is that the list is sorted so you dont need to iterate each time you can just check the values next to each other.

ListNode* LinkedList::deleteDuplicates(ListNode* head)
{
    // Check if list is empty
    if(head == nullptr)
    {
        return head;
    }

    ListNode* new_list = new ListNode; // new list
    new_list->next = nullptr;
    ListNode* new_ptr = new_list; // ptr to build the new list


    // Traverse the this list
    ListNode* current = head;
    while(current != nullptr)
    {
        // Check for duplicates
        // 1. create bool to keep track of dups
        // 2. traverse the new list and check if it has the current.val
        bool is_dup = false;
        ListNode* temp_current = new_list->next; // original new_ptr->next;
        while(temp_current != nullptr)
        {
            if(temp_current->val == current->val)
            {
                is_dup = true;
            }
            temp_current = temp_current->next;
        }

        // If not duplicate. set node to new_ptr and iteratre to the next element
        if(!is_dup)
        {
            new_ptr->next = current; // make the ptr point to the original list starting with the non-dup node
            new_ptr = new_ptr->next; // iterate the new_ptr to the newly added node
            current = current->next; // iterate the this list
            new_ptr->next = nullptr; // set the node after the newly added node to be nullptr (break off the list)


        }
        else // if duplcate. delete the dup node and iterate to the next node.
        {
            ListNode* delete_node = current;
            current = current->next;
            delete delete_node;
            delete_node = nullptr;
            new_ptr->next = nullptr;

        }
    }

    head = new_list->next;
    delete new_list;
    new_list = nullptr;
    new_ptr = nullptr;

    return head;



// How it is in leetcode original:
  // Check if list is empty
  // if(head == nullptr)
  // {
  //   return head;
  // }
  //
  // ListNode* new_list = new ListNode; // new list
  // new_list->next = nullptr;
  // ListNode* new_ptr = new_list; // ptr to build the new list
  //
  //
  // // Traverse the this list
  // ListNode* current = head;
  // while(current != nullptr)
  // {
  //   // Check for duplicates
  //   // 1. create bool to keep track of dups
  //   // 2. traverse the new list and check if it has the current.val
  //   bool is_dup = false;
  //   ListNode* temp_current = new_list->next; // original new_ptr->next;
  //   while(temp_current != nullptr)
  //   {
  //     if(temp_current->val == current->val)
  //     {
  //       is_dup = true;
  //     }
  //     temp_current = temp_current->next;
  //   }
  //
  //   // If not duplicate. set node to new_ptr and iteratre to the next element
  //   if(!is_dup)
  //   {
  //     new_ptr->next = current; // make the ptr point to the original list starting with the non-dup node
  //     new_ptr = new_ptr->next; // iterate the new_ptr to the newly added node
  //     current = current->next; // iterate the this list
  //     new_ptr->next = nullptr; // set the node after the newly added node to be nullptr (break off the list)
  //
  //
  //   }
  //   else // if duplcate. delete the dup node and iterate to the next node.
  //   {
  //     ListNode* delete_node = current;
  //     current = current->next;
  //     delete delete_node;
  //     delete_node = nullptr;
  //     new_ptr->next = nullptr;
  //
  //   }
  // }
  //
  // head = new_list->next;
  // delete new_list;
  // new_list = nullptr;
  // new_ptr = nullptr;
  //
  // return head;




  // Another more efficient way
  // Node* current = root;
  // while(current != nullptr && current->next != nullptr)
  // {
  //   if(current->val == current->next->val)
  //   {
  //     current->next = current->next->next;
  //   }
  //   else
  //   {
  //     current = current->next;
  //   }
  // }
  //
  // return root;
}


bool LinkedList::isDup(int value, ListNode* list1)
{
    ListNode* current = list1;
    while(current != nullptr)
    {
        if(current->val == value)
        {
            return true;
        }
        current = current->next;
    }

    return false;

}

ListNode* LinkedList::get_head()
{
    return head;
}

// Leet Code add two numbers(M) 2
ListNode* LinkedList::addTwoNumbers(ListNode* l1, ListNode* l2)
{
    // Original Approach works but does not pass because STL std::stoll cannot handle large strings
    // long long sum = 0;
    // std::string l1_values;
    // std::string l2_values;
    // std::string sum_values;
    //
    // // Save the l1 values into the first string
    // ListNode* l1_current  = l1;
    // while(l1_current != nullptr)
    // {
    //     l1_values += std::to_string(l1_current->val);
    //     l1_current = l1_current->next;
    // }
    //
    // // Save the l2 values into the second string
    // ListNode* l2_current = l2;
    // while(l2_current != nullptr)
    // {
    //     l2_values += std::to_string(l2_current->val);
    //     l2_current = l2_current->next;
    // }
    //
    // std::reverse(l1_values.begin(), l1_values.end()); // reverse string l1
    // std::reverse(l2_values.begin(), l2_values.end()); // reverse string l2
    //
    // // Convert l1 and l2 back to integers and them up into the sum
    // sum = std::stoll(l1_values) + std::stoll(l2_values);
    //
    // // Convert sum into a string
    // sum_values = std::to_string(sum);
    // std::reverse(sum_values.begin(), sum_values.end()); // reverse the sum
    //
    // // Create a new list
    // ListNode* sum_list = new ListNode();
    // ListNode* sum_current = sum_list; // new list index
    // // convert each character from the sum string into a int and place into the new list
    // std::string character;
    // for(int i = 0; i < sum_values.size(); i++)
    // {
    //     character = sum_values[i];
    //     sum_current->next = new ListNode(std::stoi(character));
    //     sum_current = sum_current->next;
    // }
    //
    // return sum_list->next;


    // Seconds Approach

    // No need to reverse
    // Reverse first list
    // ListNode* next = nullptr;
    // ListNode* prev = nullptr;
    // ListNode* current = l1;
    // while(current != nullptr)
    // {
    //     next = current->next;
    //     current->next = prev;
    //     prev = current;
    //     current = next;
    // }
    // l1 = prev;
    //
    // // Reverse second list
    // next = nullptr;
    // prev = nullptr;
    // current = l2;
    // while(current != nullptr)
    // {
    //     next = current->next;
    //     current->next = prev;
    //     prev = current;
    //     current = next;
    // }
    // l2 = prev;

    // Calculations and build the sum list
    // The algorithm is almost complete you just need to figure out how to properly attend to the carry over.


    // Second Algorithm works and passes 100% but can be cleaned up
    ListNode* sum_list = new ListNode(); // new list
    ListNode* sum_current = sum_list;

    ListNode* l1_current = l1; // iterator for first list
    ListNode* l2_current = l2; // iterator for first list

    int carry_over = 0;
    bool carry_over_used = false;
    while(l1_current != nullptr && l2_current != nullptr)
    {
        if(carry_over_used)
        {
            carry_over = 0;
        }

        int sum = l1_current->val + l2_current->val + carry_over;
        if(sum >= 10)
        {
            carry_over = sum - (sum - 1);
            sum_current->next = new ListNode(sum - 10); // if with carry over we subtract the by 10 for example 19 - 10 = 9, carry over is 1
            carry_over_used = false;
        }
        else
        {
            sum_current->next = new ListNode(sum);
            carry_over_used = true;
        }
        sum_current = sum_current->next;
        l1_current = l1_current->next;
        l2_current = l2_current->next;
    }

    // if list still has elements
    while(l1_current != nullptr)
    {
        if(carry_over_used)
        {
            carry_over = 0;
        }
        int sum = l1_current->val + carry_over;
        if(sum >= 10)
        {
            carry_over = sum - (sum - 1);
            sum_current->next = new ListNode(sum - 10);
            carry_over_used = false;
        }
        else
        {
            sum_current->next = new ListNode(sum);
            carry_over_used = true;
        }
        sum_current = sum_current->next;
        l1_current = l1_current->next;
    }
    while(l2_current != nullptr)
    {
        if(carry_over_used)
        {
            carry_over = 0;
        }

        int sum = l2_current->val + carry_over;
        if(sum >= 10)
        {
            carry_over = sum - (sum - 1);
            sum_current->next = new ListNode(sum - 10);
            carry_over_used = false;
        }
        else
        {
            sum_current->next = new ListNode(sum);
            carry_over_used = true;
        }
        sum_current = sum_current->next;
        l2_current = l2_current->next;
    }

    // If there is still a carry over
    if(!carry_over_used)
    {
        sum_current->next = new ListNode(carry_over);
    }
        head = sum_list->next;
    return head;
}

