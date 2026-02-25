class Solution {
public:
    bool isPalindrome(string& s, int start, int end) {
        while (start <= end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    int minCut(string s) {
        vector<int> dp(s.size() + 1, 0);
        for (int i = s.size() - 1; i >= 0; i--) {
            int minCost = INT_MAX;
            for (int j = i; j < s.size(); j++) {
                if (isPalindrome(s, i, j)) {
                    int cost = 1 + dp[j + 1];
                    minCost = min(minCost, cost);
                }
            }
            dp[i] = minCost;
        }
        return dp[0] - 1;
    }
};