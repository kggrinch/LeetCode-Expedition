#include <iostream>
#include <stack>
#include <unordered_map>

bool isValid(std::string s)
{
    // Problem - 1. Given a string of input characters that represent different type of parenthesis
    //           2. Determine if the input string is valid if the parenthesis:
    //           3. Open brackets are closed by the same closed bracket
    //           4. Open brackets must be closed in the correct order
    //           5. Every close bracket has a corresponding open bracket of the same type.

    // Solution - 1. First use a stack to hold the characters in the string
    //            2. Use a hashmap to key map closed brackets with open brackets
    //            3. In the implementation we will only store the open brackets in the stack
    //            4. If we run into a closed bracket we assume that there is a open bracket in the stack, and more specifically
    //               we assume that the corresponding open bracket is at the top of the stack.
    //            5. With this implementation, if we run into a closed bracket and the stack is empty or the corresponding open bracket
    //               is not at the top of the stack we assume that there is either a missing corresponding bracket or the order is off, therefore,
    //               we return false;
    //            6. In a sunny day scenario the open brackets are inserted into the stack first then the corresponding closed brackets
    //               are met and we compare which open bracket is on the top. With every right corresponding bracket we pop the open brackets
    //               and continue with the next brackets in the string. In the end we will end up with an empty stack where each open bracket met
    //               with their closed brackets so all open brackets were popped from the stack

    std::stack<char> stack; // O(n)
    // <Key: closed bracket, Value: open bracket>
    std::unordered_map<char, char> closeToOpen // O(1)
    {
        {')', '('},
        {']', '['},
        {'}','{'}
    };

    for(const char& c : s) // O(n)
    {
        // Check if c is a closed bracket
        if(closeToOpen.count(c))
        {
            // If the stack is not empty and the top bracket in the stack
            // corresponds to the c, the closing bracket, than pop the open bracket from the stack
            if(!stack.empty() && stack.top() == closeToOpen[c])
            {
                stack.pop();
            }
            // If the stack is empty while were at the closing bracket = no corresponding open bracket so return false.
            // If the top bracket does not correspond with c the closing bracket = the order is incorrect return false.
            else
            {
                return false;
            }
        }
        // Else c is an open bracket push into the stack
        else
        {
            stack.push(c);
        }
    }

    // Return true if the stack is empty. False if the stack is not empty
    // This is because there can be an open bracket with no corresponding closed bracket, resulting in the stack holding
    // an open bracket that never met its corresponding closed bracket
    return stack.empty();

    // Time Complexity: O(n)
    // Space Complexity: O(n)
}

int main()
{
    std::string s = "[]";
    std::cout << isValid(s);
    return 0;
}
