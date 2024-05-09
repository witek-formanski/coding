#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        mirror(nums, 0, nums.size() - 1);
        mirror(nums, 0, k - 1);
        mirror(nums, k, nums.size() - 1);
    }
private:
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void mirror(vector<int>& nums, int start, int end) {
        for (int i = 0; i < (end - start + 1) / 2; i++) {
            swap(nums, start + i, end - i);
        }
    }
};