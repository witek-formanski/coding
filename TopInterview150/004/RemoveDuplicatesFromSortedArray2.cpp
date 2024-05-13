#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int tailIndex = 0;
        int sameCount = 1;
        int tailNumber = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == tailNumber) {
                sameCount++;
                continue;
            }

            if (sameCount == 1) {
                tailIndex++;
                nums[tailIndex] = nums[i];
                tailNumber = nums[i];
                continue;
            }

            tailIndex += 2;
            nums[tailIndex - 1] = nums[i - 1];
            nums[tailIndex] = nums[i];
            tailNumber = nums[i];
            sameCount = 1;
        }

        if (sameCount > 1) {
            tailIndex++;
            nums[tailIndex] = nums[nums.size() - 1];
        }

        return tailIndex + 1;
    }
};