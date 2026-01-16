
class Solution {
   public:
    int solve(int row, int col1, int col2, vector<vector<int>>& matrix,
              vector<vector<vector<int>>>& dp) {
        if (col1 < 0 || col1 >= matrix[0].size() || col2 < 0 ||
            col2 >= matrix[0].size()) {
            return -1e9;
        }
        if (row == matrix.size() - 1) {
            if (col1 == col2)
                return matrix[row][col1];
            else
                return matrix[row][col1] + matrix[row][col2];
        }

        if (dp[row][col1][col2] != -1) {
            return dp[row][col1][col2];
        }
        int maxAns = INT_MIN;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int robotCollection = INT_MIN;
                int current = (col1 == col2 )
                                  ? matrix[row][col1]
                                  : matrix[row][col1] + matrix[row][col2];
                robotCollection =
                    current + solve(row + 1, col1 + i, col2 + j, matrix, dp);
                maxAns = max(robotCollection, maxAns);
            }
        }
        return dp[row][col1][col2] = maxAns;
    }

    int cherryPickup(vector<vector<int>>& matrix) {
        vector<vector<vector<int>>> dp(
            matrix.size(),
            vector<vector<int>>(matrix[0].size(),
                                vector<int>(matrix[0].size(), -1)));
        return solve(0, 0, matrix[0].size() - 1, matrix, dp);
    }
};
