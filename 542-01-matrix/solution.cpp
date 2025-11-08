class Solution {
public:
    bool isValid(int row, int column, int n, int m) {
        if (row < 0 || row >= n)
            return false;
        if (column < 0 || column >= m)
            return false;
        return true;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>> grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    visited[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int rowDelta[] = {0, -1, 1, 0};
        int colDelta[] = {1, 0, 0, -1};

        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            int r = node.first;
            int c = node.second;
            for (int j = 0; j < 4; j++) {
                int newRow = r + rowDelta[j];
                int newCol = c + colDelta[j];
                if (isValid(newRow, newCol, n, m) &&
                    grid[newRow][newCol] == 1 &&
                    visited[newRow][newCol] == -1) {
                    visited[newRow][newCol] = visited[r][c] + 1;
                    q.push({newRow, newCol});
                }
            }
        }
        return visited;
    }
};