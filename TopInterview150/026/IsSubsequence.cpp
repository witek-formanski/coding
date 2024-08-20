#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sIt = 0, tIt = 0;
        int sLen = s.length(), tLen = t.length();

        while (sIt < sLen) {
            while (s[sIt] != t[tIt] && tIt < tLen) {
                tIt++;
            }

            if (tIt == tLen) {
                return false;
            }

            sIt++; // it's certain that s[sIt] == t[tIt]
            tIt++;
        }

        return true;
    }
};