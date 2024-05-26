#include <sstream>
#include <vector>
#include <cctype>

using namespace std;

class Solution {
   public:
    string reverseWords(string s) {
        vector<string> words;
        int n = s.length();
        string w;

        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                w = s[i];
                i++;
                while (i < n && s[i] != ' ') {
                    w += s[i];
                    i++;
                }
                words.push_back(w);
            }
        }

        string result = "";

        for (int i = words.size() - 1; i > 0; i--) {
            result.append(words[i]);
            result += " ";
        }
        result.append(words[0]);

        return result;
    }
};