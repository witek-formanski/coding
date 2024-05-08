#include <vector>
#include <stack>

using namespace std;

/*
    T(n) = O(n)
    M(n) = O(1)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int currentMajorityElement = nums[0];
        int count = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (count == 0) {
                currentMajorityElement = nums[i];
                count++;
            } else if (currentMajorityElement == nums[i]) {
                count++;
            } else {
                count--;
            }
        }

        return currentMajorityElement;
    }
};