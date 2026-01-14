class Solution {
public:
    // Memoization
    //  int solve(int row, int col, int m, int n, vector<vector<int>>& matrix,
    //            vector<vector<int>>& dp) {
    //      if (col < 0 || col >= n)
    //          return 1e9;
    //      if (row == 0) {
    //          return matrix[0][col];
    //      }
    //      if (dp[row][col] != -1) {
    //          return dp[row][col];
    //      }
    //      int straight = matrix[row][col] + solve(row - 1, col, m, n, matrix,
    //      dp); int upLeft =
    //          matrix[row][col] + solve(row - 1, col - 1, m, n, matrix, dp);
    //      int upRight =
    //          matrix[row][col] + solve(row - 1, col + 1, m, n, matrix, dp);

    //     return dp[row][col] = min(straight, min(upLeft, upRight));
    // }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // Memoization
        //  int m = matrix.size();
        //  int n = matrix[0].size();
        //  int mini = INT_MAX;
        //  vector<vector<int>> dp(m, vector<int>(n, -1));

        // for (int i = 0; i < n; i++) {
        //     int answer = solve(m - 1, i, m, n, matrix, dp);
        //     mini = min(mini, answer);
        // }
        // return mini;
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> dp(n,-1);
        for (int i = 0; i < n; i++) {
            dp[i] = matrix[0][i];
        }

        for (int row = 1; row < m; row++) {
            vector<int> temp(n);
            for (int col = 0; col < n; col++) {

                int upLeft, upRight;
                int straight = matrix[row][col] + dp[col];
                if (col - 1 >= 0 && col - 1 < n) {
                    upLeft = matrix[row][col] + dp[col - 1];
                } else
                    upLeft = 1e9;

                if (col + 1 >= 0 && col + 1 < n) {
                    upRight = matrix[row][col] + dp[col + 1];
                } else
                    upRight = 1e9;

                temp[col] = min(straight, min(upLeft, upRight));
            }
            dp = temp;
        }

        int minAns = INT_MAX;
        for (int i = 0; i < n; i++) {
            minAns = min(minAns, dp[i]);
        }
        return minAns;
    }
};