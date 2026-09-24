class Solution {
public:
    void helper(int index, string digits, vector<string> combos,
                vector<string>& ans, string temp) {
        if (index >= digits.size()) {
            ans.push_back(temp);
            return;
        }
        int digit = (digits[index]) - '0';
        for (int i = 0; i < combos[digit].size(); i++) {
            temp.push_back(combos[digit][i]);
            helper(index + 1, digits, combos, ans, temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> combos = {"",    "",    "abc",  "def", "ghi",
                                 "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string temp;
        helper(0, digits, combos, ans, temp);
        return ans;
    }
};