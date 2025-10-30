#include <iostream>


// add_helper
int add_helper(int a, int b)
{
    int carry{};
    int sum{};
    int right_shift{};
    while ( a || b || carry)
    {
        int first_bit_a = a & 1;
        int first_bit_b = b & 1;
        if (first_bit_a == 0 && first_bit_b == 0)
        {
            // check if carry
            if (carry)
            {
                sum ^= 1 << right_shift;
                carry = 0;
            }
            else
            {
                sum^= 0;
            }
        }
        else if ( (first_bit_a == 1 && first_bit_b == 0) || (first_bit_a == 0 && first_bit_b == 1) )
        {
            if (carry)
            {
                sum^= 0;
                carry = 1;
            }
            else
            {
                sum ^= 1 << right_shift;
            }
        }
        else // first_bit_a == 1 && first_bit_b == 1
        {
            if (carry)
            {
                sum^= 1 << right_shift;
                carry = 1;
            }
            else
            {
                sum^= 0;
                carry = 1;
            }
        }
        a >>= 1;
        b >>= 1;
        right_shift++;
    }
    return sum;
}

// Brute Force Approach
// Issue: Does not work with negatives
// Time Complexity: O(1)
// Space Complexity: O(1)
int getSum(int a, int b)
{
    // Idea here is that the helper will solve the addition but only if values are not negative.
    // Therefore, I was trying to use 2 complement before sending the values into the helper function
    // to solve the addition.
    if (a < 0 || b < 0)
    {
        if (a < 0)
        {
            a = !a;
            a = add_helper(a, 1);
        }
        if (b < 0)
        {
            b = !b;
            b = add_helper(b, 1);
        }
        return add_helper(a, b);
    }
    return add_helper(a, b);
}

// Optimized Solution
// Time Complexity: O(1)
// Space Complexity: O(1)
int getSum_optimized(int a, int b)
{

    // a = sum = Carry + (a XOR b)
    // b = Carry = (a & b << 1)
    while (b)
    {
         int temp = (a & b) << 1;
         a = a ^ b;
         b = temp;
    }
    return a;
}




int main()
{
    std::cout << getSum_optimized(9, 11) << "\n";
    return 0;
}