#include <vector>
#include <algorithm>

using namespace std;

/*
    T(n) = O(n log(n))
    M(n) = O(1)
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int size = citations.size(), hIndex = 0;

        for (int i = 0; i < size; i++) {
            if (citations[i] >= size - i) {
                hIndex = max(hIndex, size - i);
            }
        }

        return hIndex;
    }
};
