class Solution {
public:
    int compress(vector<char>& chars) {
        int currLen = 1;
        int pos = 0;
        chars.push_back('~');
        for (int i = 1; i < chars.size(); i++) {
            if (chars[i] == chars[i - 1]) {
                currLen++;
            } else if (chars[i] != chars[i - 1]) {
                chars[pos] = chars[i - 1];
                pos++;
                if (currLen > 1) {
                    if (currLen < 10) {
                        chars[pos] = currLen + '0';
                        pos++;
                    } else {
                        string num = to_string(currLen);
                        for (int i = 0; i < num.size(); i++) {
                            chars[pos] = num[i];
                            pos++;
                        }
                    }
                    currLen = 1;
                }
            }
        }
            return pos;
        }
};