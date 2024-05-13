#include <vector>
#include <algorithm>

using namespace std;

/*
    T(n) = O(n)
    M(n) = O(1)
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size(),  i = 0, reach = nums[0], jumpsCount = 0, lastIndex = 0;
        while (lastIndex < size - 1) {
            reach = max(reach, i + nums[i]);
            if (i == lastIndex) {
                jumpsCount++;
                lastIndex = reach;
            }
            i++;
        }

        return jumpsCount;
    }
};
