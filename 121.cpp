#include <iostream>
#include <vector>
#include <algorithm> // For std::max

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pnt1 = 0;
        int pnt2 = 1;
        int maxp = 0;
        while (pnt2 < prices.size()) {
            if (prices[pnt1] < prices[pnt2]) {
                int p = prices[pnt2] - prices[pnt1];
                maxp = max(maxp, p);
            } else {
                pnt1 = pnt2;
            }
            pnt2 += 1;
        }
        return maxp;
    }
};

// Helper function to print results
void printResults(const vector<int>& prices, int profit) {
    cout << "Prices: [";
    for (size_t i = 0; i < prices.size(); ++i) {
        cout << prices[i];
        if (i < prices.size() - 1) cout << ", ";
    }
    cout << "]\nMax Profit: " << profit << endl;
}

int main() {
    // Test case
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    Solution solution;
    int profit = solution.maxProfit(prices);

    printResults(prices, profit);

    return 0;
}

/*
121. Best Time to Buy and Sell Stock

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
*/