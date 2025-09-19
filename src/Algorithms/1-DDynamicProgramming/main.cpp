#include <iostream>
#include <vector>
#include <unordered_map>

// Recursive
// Time Complexity: O(2^n)
int fib_recursive(int n)
{
    if(n <= 1) return n;
    return fib_recursive(n-1) + fib_recursive(n-2);
}

// Dynamic Programming Top Down using memoization
// Note: Notice how this saves solutions of subproblems in a look table (vector)
//       this solution uses a hashmap but a prebuilt array can also work
// Time Complexity: O(n) - each problem is generated once
// Space Complexity: O(n) - look up table holds n solutions
int fib_dp_memoization(int n, std::unordered_map<int, int>& memo)
{
    if(n <= 1) return n;
    if(memo.contains(n)) return memo[n];
    memo[n] = fib_dp_memoization(n-1, memo) + fib_dp_memoization(n-2, memo);
    return memo[n];
}

// Dynamic Programming Bottom Up using tabulation
// Note: Notice how this uses an iterative approach
//       This solution uses a vector but a hashmap can also work
// Time Complexity: O(n) - each problem is generated once
// Space Complexity: O(n) - look up table holds n solutions
int fib_dp_tabulation(int n)
{
    if(n <= 1) return n;
    std::vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}


int main()
{
    // Dynamic Programming - technique for solving problems by breaking them down into smaller problems and
    //                       storing the results of these problems to avoid redundant work. It’s used when a problem has
    //                       overlapping subproblems and optimal substructure.

    // Dynamic Programming Indicators
    // 1. Sequential Decision-making
    // 2. Greedy Choice Property
    // 3. State Transition
    // 4. Path or Array
    // 5. Counting or Maximization/Minimization

    // Steps to Solve Dynamic Programming Problems
    //     1. Identify if it has overlapping subproblems and optimal substructure.
    //     2. Define the states
    //     3. Write the recurrence relation / transition formula – how do subproblems combine?
    //     4. Decide the approach – Top-down (recursion + memoization) or Bottom-up (iterative tabulation).
    //     5. Initialize base cases - smallest subproblems whose answers are known.
    //     6. Compute and store results – either recursively or iteratively.
    //     7. Return the final answer – typically stored in dp[n] or equivalent.a

    int n = 5;
    std::unordered_map<int, int> memo;
    std::cout << "Recursive: " << fib_recursive(6) << "\n";
    std::cout << "Memoization(Top Down): "<< fib_dp_memoization(6, memo) << "\n";
    std::cout << "Tabulation(Bottom Up): "<< fib_dp_tabulation(6) << "\n";

    return 0;
}
