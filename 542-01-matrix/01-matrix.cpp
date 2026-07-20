class Solution {
public:
    bool isValid(int r, int c, int n, int m) {
        if (r < 0 || r >= n)
            return false;
        if (c < 0 || c >= m)
            return false;
        return true;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> visited(n, vector<int>(m, -1));
        int delrow[] = {0, 0, -1, 1};
        int delCol[] = {-1, 1, 0, 0};
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    visited[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto [first, second] = q.front();
            q.pop();
            for (int ind = 0; ind < 4; ind++) {
                int newRow = delrow[ind] + first;
                int newCol = delCol[ind] + second;
                if (isValid(newRow, newCol, n, m) &&
                    visited[newRow][newCol] == -1 && mat[newRow][newCol]==1) {
                    visited[newRow][newCol] = visited[first][second] + 1;
                    q.push({newRow,newCol});
                }
            }
        }
        return visited;
    }
};