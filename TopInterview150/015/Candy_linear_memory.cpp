#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        if (size == 1) {
            return 1;
        }

        int candiesCount = 0;
        vector<int> candies(size, 1);
        
        for (int i = 1; i < size; i++) {
            if (ratings[i - 1] < ratings[i]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        for (int i = size - 2; i >= 0; i--) {
            if (ratings[i + 1] < ratings[i]) {
                candies[i] = max(candies[i + 1] + 1, candies[i]);
            }
        }

        for (int i = 0; i < size; i++) {
            candiesCount += candies[i];
        }

        return candiesCount;
    }
};
