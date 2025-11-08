class Solution {
public:
    bool isValid(int row, int col, int n, int m) {
        if (row < 0 || row >= n) return false;
        if (col < 0 || col >= m) return false;
        return true;
    }
    void BFS(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &vis) {
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = 1;

        int n=grid.size();
        int m=grid[0].size();
        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            int row = node.first;
            int col = node.second;
            
            int delRow[]={-1,0,1,0};
            int delCol[]={0,1,0,-1};
            for (int i = 0; i < 4; i++) {
                    int newRow = row + delRow[i];
                    int newCol = col + delCol[i];

                    if (isValid(newRow, newCol, n, m) &&
                        grid[newRow][newCol] == '1' && !vis[newRow][newCol]) {
                        vis[newRow][newCol] = 1;
                        q.push({newRow, newCol});
                    }
                }
            }
        }

    int numIslands(vector<vector<char>> &grid) {
        int V = grid.size();
        int cnt = 0;
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]== '1') {
                    if (!vis[i][j]) {
                        cnt++;
                        BFS(i, j, grid, vis);
                    }
                }
            }
        }
        return cnt;
    }
};