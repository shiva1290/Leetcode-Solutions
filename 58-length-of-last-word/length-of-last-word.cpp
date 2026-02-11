class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        int len = 0;
        bool word = false;
        while (i >= 0) {
            if (s[i] == ' ' && word) {
                break;
            } else if (s[i] != ' ') {
                if(!word){
                    word=true;
                    len++;
                }
                else len++;
            }
            i--;
        }
        return len;
    }
};