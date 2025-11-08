class Solution {
public:
    bool checkValidString(string s) {
        int minVal = 0;
        int maxVal = 0;
        for (char c : s) {
            if (c == '(') {
                minVal++;
                maxVal++;
            } else if (c == '*') {
                minVal--;
                maxVal++;
            } else if (c == ')') {
                minVal--;
                maxVal--;
            }
            if (minVal < 0)
                minVal = 0;
            if (maxVal < 0)
                return false;
        }
        return (minVal == 0);
    }
};