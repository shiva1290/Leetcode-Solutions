class Solution {
public:
    string largestOddNumber(string s) {
        int j = s.size() - 1;
        int odd = -1;
        while (j >= 0) {
            if ((s[j] - '0') % 2 != 0) {
                odd = j;
                break;
            }
            j--;
        }
        if (odd == -1)
            return "";
        j = 0;
        while (s[j] == '0') {
            j++;
        }

        return s.substr(j, odd - j + 1);
    }
};