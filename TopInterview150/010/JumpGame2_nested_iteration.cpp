#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

/*
    T(n) = O(n^2)
    M(n) = O(n)
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size(), range;
        vector<int> minJumpsCounts(size, INT_MAX - 1);
        minJumpsCounts[0] = 0;

        for (int i = 0; i < size - 1; i++) {
            range = min(i + nums[i] + 1, size);
            for (int j = i + 1; j < range; j++) {
                minJumpsCounts[j] = min(minJumpsCounts[j], minJumpsCounts[i] + 1);
            }
        }

        return minJumpsCounts[size - 1];
    }
};
