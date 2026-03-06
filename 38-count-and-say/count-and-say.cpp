class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        string ans = "";
        string prev = countAndSay(n - 1);
        int count = 1;
        for (int i = 1; i < prev.size(); i++) {
            if (prev[i] == prev[i - 1])
                count++;
            else {
                ans += '0' + count;
                ans += prev[i - 1];
                count = 1;
            }
        }
        ans += '0' + count;
        ans += prev[prev.size() - 1];
        return ans;
    }
};