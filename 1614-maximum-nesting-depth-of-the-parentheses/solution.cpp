class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        int maxCnt = 0;
        for (char ch : s) {
            if (ch == '(')
                cnt++;
            if (ch == ')') {
                maxCnt = max(maxCnt, cnt);
                cnt--;
            }
        }
        return maxCnt;
    }
};