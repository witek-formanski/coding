#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;
        int result = 0;

        while (s[i] == ' ') {
            i--;
        }

        while (i >= 0 && s[i] != ' ') {
            result++;
            i--;
        }

        return result;        
    }
};