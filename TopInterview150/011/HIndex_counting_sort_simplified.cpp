#include <vector>
#include <algorithm>

using namespace std;

/*
    T(n) = O(n)
    M(n) = O(n)
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        vector<int> articlesPerCounts(size + 1, 0);

        for (int citation : citations) {
            if (citation >= size) {
                articlesPerCounts[size]++;
            } else {
                articlesPerCounts[citation]++;
            }
        }

        int articlesCount = 0;
        for (int i = size; i >= 0; i--) {
            articlesCount += articlesPerCounts[i];
            if (articlesCount >= i) {
                return i;
            }
        }

        return 0;
    }
};
