class Solution {
public:
    void helper(int index, string digits, vector<string>& alphabets,
                vector<string>& ans, string s) {
        if (index == digits.size()) {
            ans.push_back(s);
            return;
        }
        int digit = digits[index] - '2';

        for (int i = 0; i < alphabets[digit].size(); i++) {
            helper(index + 1, digits, alphabets, ans, s + alphabets[digit][i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> alphabets = {"abc", "def",  "ghi", "jkl",
                                    "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string s;
        helper(0, digits, alphabets, ans, s);
        return ans;
    }
};