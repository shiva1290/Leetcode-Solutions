class Solution {
public:
    // int solve(int row, int col, vector<vector<int>>& triangle,
    //           vector<vector<int>>& dp) {
    //     if (row == 0) {
    //         return triangle[0][0];
    //     }
    //     int upLeft = INT_MAX;
    //     int up = INT_MAX;

    //     if (dp[row][col] != -1) {
    //         return dp[row][col];
    //     }

    //     if (col <= row - 1) {
    //         up = triangle[row][col] + solve(row - 1, col, triangle, dp);
    //     }
    //     if (col - 1 >= 0) {
    //         upLeft = triangle[row][col] + solve(row - 1, col - 1, triangle,
    //         dp);
    //     }
    //     return dp[row][col] = min(up, upLeft);
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n, -1);
        dp[0] = triangle[0][0];
        for (int row = 1; row < n; row++) {
            vector<int>temp(n);
            for (int col = 0; col < triangle[row].size(); col++) {
                int upLeft = INT_MAX;
                int up = INT_MAX;
                if (col <= row - 1) {
                    up = triangle[row][col] + dp[col];
                }
                if (col - 1 >= 0) {
                    upLeft = triangle[row][col] + dp[col - 1];
                }
                temp[col] = min(up, upLeft);
            }
            dp=temp;
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (dp[i] < ans) {
                ans = dp[i];
            }
        }
        return ans;
    }
};