#include <iostream>
#include <stack>

// Helper to check matching brackets
bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Check balanced brackets
bool isBalanced(const std::string& expr) {
    std::stack<char> st;

    for (char ch : expr)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (st.empty() || !isMatchingPair(st.top(), ch))
            {
                return false;
            }
            st.pop();
        }
    }

    return st.empty();
}

// Check basic syntax validity
bool isValidSyntax(const std::string& expr)
{
    bool expectOperand = true; // Start expecting operand

    for (int i = 0; i < expr.length(); i++)
    {
        char ch = expr[i];

        if (isspace(ch)) continue;

        if (isalnum(ch))
        {
            if (!expectOperand) return false;
            expectOperand = false;
        }
        else if (ch == '(' || ch == '{' || ch == '[')
        {
            if (!expectOperand) return false;
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (expectOperand) return false;
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        {
            if (expectOperand) return false;
            expectOperand = true;
        }
        else
        {
            return false; // Invalid character
        }
    }

    return !expectOperand; // Expression should not end with operator
}

// Combined check
bool isValidExpression(const std::string& expr)
{
    return isBalanced(expr) && isValidSyntax(expr);
}

// Main function
int main() {
    std::string expr;

    std::cout << "Enter expression: ";
    getline(std::cin, expr);

    if (isValidExpression(expr)) {
        std::cout << "Valid and Balanced Expression" << std::endl;
    } else {
        std::cout << "Invalid Expression" << std::endl;
    }

    return 0;
}