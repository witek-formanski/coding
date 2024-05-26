#include <algorithm>
#include <vector>

using namespace std;

class Solution {
   public:
    int trap(vector<int>& height) {
        int n = height.size();
        int heighestLeft = height[0];
        int heighestRight = height[n - 1];
        int left = 1;
        int right = n - 2;
        int trappedWater = 0;

        while (left <= right) {
            if (heighestLeft < heighestRight) {
                if (height[left] > heighestLeft) {
                    heighestLeft = height[left];
                } else {
                    trappedWater += heighestLeft - height[left];
                }
                left++;
            } else {
                if (height[right] > heighestRight) {
                    heighestRight = height[right];
                } else {
                    trappedWater += heighestRight - height[right];
                }
                right--;
            }
        }

        return trappedWater;
    }
};