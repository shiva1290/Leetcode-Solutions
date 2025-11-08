class Solution{
public:
    bool isValid(int row, int column, int n, int m) {
        if (row < 0 || row >= n) return false;
        if (column < 0 || column >= m) return false;
        return true;
    }
    void BFS(vector<vector<char>> &grid, vector<vector<int>> &visited,
             queue<pair<int, int>> &q) {
        int n = grid.size();
        int m = grid[0].size();

        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            int row = node.first;
            int col = node.second;

            int rowDelta[] = {-1, 0, 0, 1};
            int colDelta[] = {0, -1, 1, 0};
            for (int i = 0; i < 4; i++) {
                int newRow = row + rowDelta[i];
                int newCol = col + colDelta[i];
                if (isValid(newRow, newCol, n, m) && !visited[newRow][newCol] &&
                    grid[newRow][newCol] == 'O') {
                    visited[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
        }
    }

    void solve(vector<vector<char>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;

        vector<vector<int>> visited(n,vector<int>(m,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) &&
                    grid[i][j] == 'O') {
                    visited[i][j] = 1 ;
                    q.push({i, j});
                }
            }
        }

        BFS(grid, visited, q);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'O' && !visited[i][j]) {
                    grid[i][j]='X';
                }
            }
        }
    }
};