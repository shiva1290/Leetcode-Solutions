class Solution {
   public:
    void helper(int open, int close, int n, string s, vector<string> &result) {
        if (open == close && open == n && close == n) {
            result.push_back(s);
        }
        if (open < n) {
            helper(open + 1, close, n, s + '(', result);
        }
        if (close < open) {
            helper(open, close + 1, n, s + ')', result);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        helper(0, 0, n, "", result);
        return result;
    }
};