#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        int n = strs.size();

        int minimalLength = INT_MAX;
        for (string s : strs) {
            if (s.length() < minimalLength) {
                minimalLength = s.length();
            }
        }

        char c;
        bool allTheSame = true;
        for (int i = 0; i < minimalLength; i++) {
            c = strs[0][i];
            for (int j = 1; j < n; j++) {
                if (strs[j][i] != c) {
                    allTheSame = false;
                    break;
                }
            }

            if (!allTheSame) {
                break;
            }

            prefix += c;
        }

        return prefix;
    }
};