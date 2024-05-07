#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int uniqueCount = 1;
        int lastUnique = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] == nums[i]) {
                continue;
            }

            uniqueCount++;
            lastUnique++;
            nums[lastUnique] = nums[i];
        }

        return uniqueCount;
    }
};