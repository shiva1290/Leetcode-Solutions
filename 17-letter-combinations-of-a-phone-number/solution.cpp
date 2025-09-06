class Solution {
public:
    void helper(int index, string digits, vector<string>& s,
                vector<string>& result, string& temp) {
        if (index == digits.size()) {
            result.push_back(temp);
            return;
        }
        int digit = digits[index] - '0';
        for (int i = 0; i < s[digit].size(); i++) {
            temp.push_back(s[digit][i]);
            helper(index + 1, digits, s, result, temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        vector<string> s = {"",    "",    "abc",  "def", "ghi",
                            "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        string temp;
        helper(0, digits, s, result, temp);
        return result;
    }
};