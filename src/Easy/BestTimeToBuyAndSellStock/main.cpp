#include <iostream>
#include <vector>

int maxProfit(std::vector<int>& prices)
{
    // Problem - 1. Given an array of prices where price[i] is the price of a stock on the i day.
    //           2. Return an int largest profit by choosing a single day to buy and a different day in the future to sell
    //           3. If there is no profit then return 0
    //           4. You must buy before you sell therefore, you cannot sell any days before the buy day.

    // Solution - (using two pointers) - right intuition but wrong approach
    //            1. Use two pointers. One starting at the begining and one at the end.
    //            2. Move the pointers towards each other while the left find the min and the right find the max until
    //               the pointers meet.
    //            3. If the pointers end up being the same return 0, if they are valid return the profit, if not return 0
    //            issue here is that the max can be right by the min and there if no right way of incrementing the pointers
    //            consistent, so the min and max are lost because the pointer cross over each other before the max and min is found.
    //
    //            (Brute Force) Time Complexity: O(n^2)
    //            1. The idea here is that every value after the buy is valid and every value before the buy is invalid
    //            2. Use an index to calculate the profit margins if each value was to be considered as a buy.
    //            3. we keep track of the first index and check the profit margins if it was compared to all value after it
    //               we then keep track of the highest profit and check the next index.
    //
    //            (Two Pointers (Sliding Window)) O(n)
    //            1. Use two pointers. Both will start at the beginning. The l pointer will start the first index and will keep track
    //               of the current buy point. The r pointer will start at the second index and will keep track of the sell point.
    //            2. At each location check if there is a profit between the pointers.
    //               a) if profit then check if its greater than current max then update current max and iterate the r pointer to next index but keep the l pointer where its at since we are still making profit
    //               b) if there is profit but its not greater than current max then just iterte the r pointer and keep the l in the same locaiton since we are still making profit
    //               c) If there is not profit and the value is negative then move the l pointer to where the r pointer is at and then increment the r pointer to next index
    //                  This is because r pointer just found the slowest buy point.
    //           This is a sliding window technique because the two pointers are iterating the array in the same direction just with conditions
    //           The l pointer is incremented toward the r pointer and r pointer keeps moving.

    // Optimal
    if(prices.size() < 2) return 0;

    int max{};
    int l = 0;
    int r = l + 1;

    while(r < prices.size()) // O(n)
    {
        int profit = prices[r] - prices[l];
        if(profit < 0)
        {
            l = r;
            r++;
        }
        else
        {
            if(profit > max) max = profit;
            r++;
        }
    }
    return max;

    // Time Complexity: O(n)
    // Space Complexity: O(1)



    // (Brute Force)
    // int max_profit{};
    // for(int i = 0; i < prices.size(); i++)
    // {
    //     int max{};
    //     for(int j = i + 1; j < prices.size(); j++)
    //     {
    //         int profit = prices[j] - prices[i];
    //         if(!(profit < 0) && profit > max) max = profit;
    //     }
    //     if(max > max_profit) max_profit = max;
    // }
    // return max_profit;

}

int main()
{
    std::vector<int> prices = {3,2,6,5,0,3};
    std::cout << "largest profit: " << maxProfit(prices);

    return 0;
}
