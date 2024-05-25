#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();
        int sum = 0;
        int minimalSum = INT_MAX;
        int minimalIndex = 0;

        for (int i = 0; i < size; i++) {
            gas[i] -= cost[i];
            sum += gas[i];
            if (sum < minimalSum) {
                minimalIndex = i;
                minimalSum = sum;
            }
        }

        if (sum < 0) {
            return -1;
        }

        return (minimalIndex == size - 1) ? 0 : minimalIndex + 1;
    }
};