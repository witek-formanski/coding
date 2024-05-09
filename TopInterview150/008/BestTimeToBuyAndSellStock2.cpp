#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimum = prices[0];
        int maximum = minimum;
        int profit = 0;
        bool increasing = true;
        for (int i = 1; i < prices.size(); i++) {
            if (increasing) {
                if (prices[i] >= maximum) {
                    maximum = prices[i];
                } else { // sell stock
                    profit += maximum - minimum;
                    increasing = false;
                    minimum = prices[i];
                }
            } else {
                if (prices[i] <= minimum) {
                    minimum = prices[i];
                } else { // buy stock
                    increasing = true;
                    maximum = prices[i];
                }
            }
        }

        if (increasing) {
            profit += maximum - minimum;
        }

        return profit;
    }
};