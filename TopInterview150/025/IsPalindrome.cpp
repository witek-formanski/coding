#include <string>

using namespace std;

class Solution {
   public:
    bool isPalindrome(string s) {
        int front = 0;
        int back = s.length() - 1;

        while (front < back) {
            while (!isAlphaNumeric((int)s[front]) && front < back) {
                front++;
            }

            while (!isAlphaNumeric((int)s[back]) && front < back) {
                back--;
            }

            if (!isAlphaNumeric((int)s[front]) && !isAlphaNumeric((int)s[back])) {
                return true;
            }

            if (!areTheSame((int)s[front], (int)s[back])) {
                return false;
            }

            front++;
            back--;
        }

        return true;
    }

   private:
    bool isAlphaNumeric(int castedChar) {
        return isNumber(castedChar) || isLetter(castedChar);
    }

    bool isNumber(int castedChar) {
        return castedChar >= 48 && castedChar <= 57;
    }

    bool isLetter(int castedChar) {
        return isCapitalLetter(castedChar) || isSmallLetter(castedChar);
    }

    bool isCapitalLetter(int castedChar) {
        return castedChar >= 65 && castedChar <= 90;
    }

    bool isSmallLetter(int castedChar) {
        return castedChar >= 97 && castedChar <= 122;
    }
    bool areTheSame(int a, int b) {
        if (isNumber(a) && isNumber(b)) {
            return a == b;
        }

        if (isLetter(a) && isLetter(b)) {
            return a % 32 == b % 32;  // using ASCII
        }

        return false;
    }
};