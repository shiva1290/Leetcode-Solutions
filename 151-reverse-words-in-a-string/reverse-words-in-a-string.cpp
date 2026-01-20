class Solution {
public:
    string reverseWords(string s) {
        int i = s.size() - 1;
        string temp;
        string result;
        while (i >= 0) {
            if (s[i] == ' ' && temp.empty()) {
                i--;
                continue;
            }

            else if (s[i] != ' ') {
                temp += s[i];
            }

            else if (s[i] == ' ' && !temp.empty()) {
                reverse(temp.begin(), temp.end());
                result += temp;
                result += ' ';
                temp.clear();
            }
            i--;
        }
        if (!temp.empty()) {
            reverse(temp.begin(), temp.end());
            result += temp;
            result += ' ';
        }
        result.pop_back();
        return result;
    }
};