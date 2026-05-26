class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> Carr(26, 0);
        vector<int> Sarr(26, 0);
        int cnt = 0 ;
        for (int i = 0; i < word.size(); i++) {
            if (isupper(word[i])) {
                Carr[word[i] - 'A']++;
            } else
                Sarr[word[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (Carr[i] != 0 && Sarr[i] != 0) {
                cnt++;
            }
        }
        return cnt;
    }
};