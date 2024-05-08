#include <vector>
#include <stack>

using namespace std;

/*
    T(n) = O(n)
    M(n) = O(n)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        stack<int> s;

        for (int i = 0; i < nums.size(); i++) {
            if (s.empty() || s.top() == nums[i]) {
                s.push(nums[i]);
            } else {
                s.pop();
            }
        }

        return s.top();
    }
};