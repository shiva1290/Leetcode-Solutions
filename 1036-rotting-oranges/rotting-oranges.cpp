class Solution {
public:
    bool isValid(int r, int c, int n, int m) {
        if (r < 0 || r >= n)
            return false;
        if (c < 0 || c >= m)
            return false;
        return true;
    }
    void BFS(vector<vector<int>>& grid, int n, int m, int& ans,queue<pair<int,int>>&q) {
        int delRow[] = {0, 0, -1, 1};
        int delCol[] = {1, -1, 0, 0};
        while (!q.empty()) {
            int size = q.size();
            ans++;
            for (int i = 0; i < size; i++) {
                auto node = q.front();
                q.pop();
                int row = node.first;
                int col = node.second;
                for (int i = 0; i < 4; i++) {
                    int newRow = row + delRow[i];
                    int newCol = col + delCol[i];
                    if (isValid(newRow, newCol, n, m) &&
                        grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 3;
                        q.push({newRow, newCol});
                    }
                }
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = -1;
        
        bool fresh=false;
        bool rotten=false;
        queue<pair<int,int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(grid[i][j]==1) fresh=true;
                if (grid[i][j] == 2) {
                    rotten=true;
                    q.push({i,j});
                    grid[i][j] = 3;
                }
            }
        }
        BFS(grid, n, m, ans,q);
        if(!fresh) return 0;
        if(!rotten) return -1;
        for(auto row : grid){
            for(auto cell : row){
                if(cell==1) return -1;
            }
        }
        return ans;
    }
};