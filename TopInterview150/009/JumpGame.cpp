#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        return canJump(nums, nums.size() - 1);
    }

private:
    bool canJump(vector<int>& nums, int index) {
        for (int i = index - 1; i > 0; i--) {
            if (nums[i] >= index - i) {
                return canJump(nums, i);
            }
        }

        return (nums[0] >= index);
    }
};