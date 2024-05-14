#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> products(size);
        products[0] = 1;

        for (int i = 1; i < size; i++) {
            products[i] = products[i - 1] * nums[i - 1];
        }

        int factor = 1;
        for (int i = size - 2; i >= 0; i--) {
            factor *= nums[i + 1];
            products[i] *= factor;
        }

        return products;
    }
};