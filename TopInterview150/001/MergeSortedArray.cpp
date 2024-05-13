#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int count = 0, i = 0, j = 0;
        vector<int> nums1_copy(nums1.begin(), nums1.begin() + m);
        while (count < m + n) {
            if (i == m) {
                while (j < n) {
                    nums1[count++] = nums2[j++];
                }
                break;
            }
            if (j == n) {
                while (i < m) {
                    nums1[count++] = nums1_copy[i++];
                }
                break;
            }

            if (nums1_copy[i] <= nums2[j]) {
                nums1[count++] = nums1_copy[i++];
            } else {
                nums1[count++] = nums2[j++];
            }
        }
    }
};