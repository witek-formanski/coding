#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimum = prices[0];
        int maximum = minimum;
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < minimum) {
                minimum = prices[i];
                maximum = minimum;
            } else if (prices[i] > maximum) {
                maximum = prices[i];
                profit = max(profit, maximum - minimum);
            }
        }

        return profit;
    }
};