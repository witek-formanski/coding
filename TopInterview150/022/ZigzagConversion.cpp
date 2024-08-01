#include <string>

using namespace std;

class Solution {
   public:
    string convert(string s, int numRows) {
        int length = s.length();
        string* rows = new string[numRows];
        int i = 0;

        for (int j = 0; j < numRows; j++)
            rows[j] = "";
        
        while (i < length) {
            for (int j = 0; j < numRows && i < length; j++, i++)
                rows[j] += s[i];
            for (int j = numRows - 2; j > 0 && i < length; j--, i++)
                rows[j] += s[i];
        }

        string result = "";

        for (int j = 0; j < numRows; j++)
            result += rows[j];

        return result;
    }
};