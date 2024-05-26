#include <algorithm>
#include <vector>

using namespace std;

class Solution {
   public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> heighestLeft(n), heighestRight(n);

        for (int i = 1; i < n; i++) {
            heighestLeft[i] = max(height[i - 1], heighestLeft[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--) {
            heighestRight[i] = max(height[i + 1], heighestRight[i + 1]);
        }

        int trappedWater = 0, waterLevel;
        for (int i = 0; i < n; i++) {
            waterLevel = min(heighestLeft[i], heighestRight[i]);
            if (waterLevel >= height[i]) {
                trappedWater += waterLevel - height[i];
            }
        }

        return trappedWater;
    }
};