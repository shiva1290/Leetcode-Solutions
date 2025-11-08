class Solution {
public:
     bool isValid(int row, int column, int n, int m) {
        if (row < 0 || row >= n) return false;
        if (column < 0 || column >= m) return false;
        return true;
    }

    int orangesRotting(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;

        queue<pair<int, int>> q;

        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                }
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        if (fresh == 0) return 0;

        int time = 0;
        int rowDelta[] = {-1, 0, 0, 1};
        int colDelta[] = {0, 1, -1, 0};

        while (!q.empty()) {
            int size = q.size();
            bool rotted = false;
            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();
                for (int j = 0; j < 4; j++) {
                    int nc = c + colDelta[j];
                    int nr = r + rowDelta[j];
                    if (isValid(nr, nc, n, m) && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                        rotted = true;
                    }
                }
            }
            if (rotted) time++;
        }
        return (fresh == 0) ? time : -1;
    }
};