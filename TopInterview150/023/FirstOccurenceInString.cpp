#include <string>

using namespace std;

class Solution {
   public:
    int strStr(string haystack, string needle) {
        int stackLength = haystack.length();
        int needleLength = needle.length();
        int i = 0;
        int j = 0;

        while (i < stackLength) {
            if (haystack[i] == needle[j])
                j++;
            else {
                i -= j;
                j = 0;
            }

            if (j == needleLength)
                return i - j + 1;
            
            i++;
        }

        return -1;
    }
};