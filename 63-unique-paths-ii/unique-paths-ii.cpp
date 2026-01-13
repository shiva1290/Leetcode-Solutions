class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> prev(n, 0);

        for (int i = 0; i < m; i++) {
            vector<int> cur(n, 0);
            for (int j = 0; j < n; j++) {
                int right = 0;
                int down = 0;
                if (matrix[i][j] == 1) {
                    cur[j] = 0;
                } else if (i == 0 && j == 0) {
                    cur[j] = 1;
                } else {
                    if (i > 0) right = prev[j];
                    if (j > 0) down = cur[j - 1];
                    cur[j] = right + down;
                }
            }
            prev = cur;
        }

        return prev[n - 1];
    }
};