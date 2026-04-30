#include<iostream>
#include<cctype>
#include <cmath>
#include<stack>

bool matching_pair(const char closing, const char opening)
{
    return (closing == ')' && opening == '(') || (closing == '}' && opening == '{') || (closing == ']' && opening == '[');
}

// O(n)
bool valid_parentheses(const std::string& s)
{
    std::stack<char> p_stack; // holds closing bracket
    for (char c : s)
    {
        if (c == ')' || c == ']' || c == '}')
        {
            if (p_stack.empty() || !matching_pair(c, p_stack.top())) return false;
            p_stack.pop();
        }
        if (c == '(' || c == '[' || c == '{')
        {
            p_stack.push(c);
        }
    }
    return p_stack.empty();
}

// Time: O(n)
bool valid_syntax(const std::string& s)
{
    bool operand{}; // expecting operand

    for (char c : s)
    {
        if(isspace(c) || c == '(' || c == '[' || c == '{' || c == ')' || c == ']' || c == '}') continue;
        else if(isalnum(c))
        {
            if (operand) return false;
            operand = true;
        }
        else if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        {
            if (!operand) return false;
            operand = false;
        }
        else return false;
    }
    return true;
}

bool valid_expression(const std::string& s)
{
    return valid_syntax(s) && valid_parentheses(s);
}

bool testing(const std::string& s, const bool expected)
{
    return valid_expression(s) == expected;
}
bool testing_suite()
{
    // Testing basic (correct)
    std::string s1_in = "1 + 2";
    std::string s2_in= "(1 + 2^3)";
    std::string s3_in= "(1 + (2 * 3)) / 5";
    if (!testing(s1_in, true)) return false;
    if (!testing(s2_in, true)) return false;
    if (!testing(s3_in, true)) return false;

    // Testing basic (incorrect)
    std::string s1_inc = "1 ++";
    std::string s2_inc = "(1 + (2^3)))";
    std::string s3_inc= "(1 + (2 * 3)) / 5 + (6^2))";
    if (!testing(s1_inc, false)) return false;
    if (!testing(s2_inc, false)) return false;
    if (!testing(s3_inc, false)) return false;


    // Testing edge cases
    std::string s1_ed = "1";
    std::string s2_ed = "+";
    std::string s3_ed = "";
    std::string s4_ed = "()";
    std::string s5_ed = "t + x";
    std::string s6_ed = "?";
    if (!testing(s1_ed, true)) return false;
    if (!testing(s2_ed, false)) return false;
    if (!testing(s3_ed, true)) return false;
    if (!testing(s4_ed, true)) return false;
    if (!testing(s5_ed, true)) return false;
    if (!testing(s6_ed, false)) return false;

    return true;
}

void test_all()
{
    if (testing_suite()) std::cout << "All tests passed\n";
    else std::cout << "Test failed\n";
}


int main()
{
    test_all();
    return 0;
}