
#include "linkedList.h"


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
  if(new_node->val < head->val)
  {
    new_node->next = head;
    head = new_node;
    return true;
  }

  // Traverse list for correct position. Return true.
  ListNode* current = head;
  while(current->next != nullptr && current->next->val < new_node->val)
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