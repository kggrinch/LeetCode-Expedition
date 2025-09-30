#include <iostream>
#include <vector>
#include <algorithm>

// Time Complexity: O( (nlogn) + m) where n = number of inputs in num and m = number of inputs allowed to retreive to calculate sum.
int largest_sum(std::vector<int> nums, const int& n)
{
    std::sort(nums.begin(), nums.end()); // n log n
    int m{};
    int result{};
    int size = nums.size() - 1;
    while (m < n) // m
    {
        result += nums[size];
        size--;
        m++;
    }
    return result;
}


int main()
{
    // Greedy Algorithm - An algorithm that makes a greedy choice (optimal choice) at every step in the solution/problem.
    //                    The greedy choice is defined by some rule, such as choose the smallest or largest value.
    //                    The greedy choice as every step is then built up that creates the overall optimal solution.


    // Greedy Algorithm Properties - if the following problem has these properties than you can use the greedy algorithm to solve it.
    //      1. Greedy Choice Property
    //          - A global (overall) optimal solution can be reached by choosing the optimal choice at each step.
    //      2. Optimal Substructure Property
    //          - A problem has an optimal substructure if an optimal solution to the entire problem contains the optimal solutions
    //            to the sub-problems.



    // Greedy Algorithm examples

    // Largest Sum Problem
    // Given an array select n values in the array to give the largest sum of the n values.
    // ex:
    // Problem: [3, 4, -1, 2, -3, 0] n = 4
    // Solution: [4, 3, 2, 0] = 9
    std::vector<int> nums = {3, 4, -1, 2, -3, 0};
    int n = 4;
    std::cout << "Largest Sum: " << largest_sum(nums, n) << "\n";


    // Fractional Knapsack problem
    // You are given a backpack with a set capacity. You are also given some items where each item has a unit of capacity
    // that it fills up in the backpack, and each item has a value. The problem is, find out what is the highest value of items you can fit into
    // your backpack given the capacity of the backpack and each item. Also, each item can be fractionally divided to fit remaining space.

    // ex:
    // Problem: Backpack capacity W = 25, Items = [(value|capacity)] = [(v=19|c=22), (v=9|c=10), (v=9|c=9), (v=6|c=7)]
    // Solution:
    // Taken smallest values first (greedy criteria ) optimal item indexes = [3, 2, 1 * 0.9] = value of 23.1
    // Taken greatest values first (greedy criteria) optimal item indexes = [0, 2*.33] = value of 22
    // Taken the greatest size/value ratio (greedy criteria)
    // size/value ratio = [0.8636, 0.9, 1, 0.857] | optimal item indexes = [2, 1, 0 * .27] = value of 23.18



    return 0;
}