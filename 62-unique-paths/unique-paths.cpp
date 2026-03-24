class Solution {
public:
    // int helper(int r, int c, int n, int m, vector<vector<int>>& dp) {
    //     if (r == n - 1 && c == m - 1) {
    //         return 1;
    //     }
    //     if (r > n - 1 || c > m - 1) {
    //         return 0;
    //     }
    //     if (dp[r][c] != -1) {
    //         return dp[r][c];
    //     }
    //     int down = 0;
    //     int right = 0;
    //     if (r + 1 < n)
    //         down = helper(r + 1, c, n, m, dp);
    //     if (c + 1 < m)
    //         right = helper(r, c + 1, n, m, dp);
    //     return dp[r][c] = down + right;
    // }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i=0;i<m;i++){
            dp[i][n-1]=1;
        }
        for(int i=0;i<n;i++){
            dp[m-1][i]=1;
        }
        for (int r = m - 2; r >= 0; r--) {
            for (int c = n - 2; c >= 0; c--) {
                int down = 0;
                int right = 0;
                if (r + 1 < m)
                    down = dp[r + 1][c];
                if (c + 1 < n)
                    right = dp[r][c + 1];
                dp[r][c] = down + right;
            }
        }
        return dp[0][0];
    }
};