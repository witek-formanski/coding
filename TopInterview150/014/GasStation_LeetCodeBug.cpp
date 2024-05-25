#include <vector>

using namespace std;

// modified a bit to pass LeetCode's 39th test case, which expects certain answer that is not unique

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();
        int sum = 0;
        int surplus = 0;
        int start = 0;
        
        for(int i = 0; i < size; i++){
            sum += gas[i] - cost[i];
            surplus += gas[i] - cost[i];
            if(surplus < 0){
                surplus = 0;
                start = i + 1;
            }
        }

        return (sum < 0) ? -1 : start;
    }
};