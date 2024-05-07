#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int head = 0;
        int tail = nums.size() - 1;
        int k = 0;

        while (head <= tail) {
            if (nums[head] != val) {
                k++;
                head++;
                continue;
            }

            // if (nums[head] == val) {
            
            if (nums[tail] == val) {
                tail--;
                continue;
            }
            
            // if (nums[head] == val && nums[tail] != val) {
            k++;
            nums[head] = nums[tail];
            head++;
            tail--;
        }

        return k;
    }
};