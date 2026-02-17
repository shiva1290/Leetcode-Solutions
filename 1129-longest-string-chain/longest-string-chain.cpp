class Solution {
public:
    bool checker(string &w1, string &w2) {
        if (w1.size() != w2.size() + 1)
            return false;
        int i = 0;
        int j = 0;
        while (i < w1.size()) {
            if (w1[i] == w2[j]) {
                i++;
                j++;
            } else
                i++;
        }
        if (i == w1.size() && j == w2.size())
            return true;

        return false;
    }
 
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(),
             [](string& a, string& b) { return a.length() < b.length(); });
        vector<int> dp(n, 1);
        vector<int> parent(n);
        vector<int> ans;

        int maxLen = 0;
        for (int index = 0; index < n; index++) {
            parent[index] = index;
            for (int lastIndex = 0; lastIndex < index; lastIndex++) {
                if (dp[index] < dp[lastIndex] + 1 &&
                    checker(words[index], words[lastIndex])) {
                    dp[index] = dp[lastIndex] + 1;
                }
            }
            if (maxLen < dp[index]) {
                maxLen = dp[index];
            }
        }
        return maxLen;
    }
};