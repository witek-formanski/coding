#include <string>
#include <unordered_map>

using namespace std;

class Solution {
   private:
    unordered_map<int, char> roman;

   public:
    Solution() {
        roman = {
            {1, 'I'},
            {5, 'V'},
            {10, 'X'},
            {50, 'L'},
            {100, 'C'},
            {500, 'D'},
            {1000, 'M'}};
    }

    string intToRoman(int num) {
        string result = "";
        int divisor = (pow(10, to_string(num).length()));
        int quotient;

        while (num > 0) {
            quotient = num / divisor;
            num -= quotient * divisor;

            if (quotient <= 3) {
                for (int i = 0; i < quotient; i++) {
                    result += roman[divisor];
                }
            } else if (quotient == 4) {
                result += roman[divisor];
                result += roman[5 * divisor];
            } else if (quotient <= 8) {
                result += roman[5 * divisor];
                for (int i = 0; i < quotient - 5; i++) {
                    result += roman[divisor];
                }
            } else if (quotient == 9) {
                result += roman[divisor];
                result += roman[10 * divisor];
            }

            divisor /= 10;
        }

        return result;
    }
};