class Solution {
public:
    bool isValid(int row, int col, int n, int m) {
        if (row < 0 || row >= n)
            return false;
        if (col < 0 || col >= m)
            return false;
        return true;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        int fresh=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        if(fresh==0) return 0;
        int steps=1;
        int time = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto node = q.front();
                q.pop();
                int rowIndex = node.first;
                int colIndex = node.second;
                int delRow[] = {-1, 1, 0, 0};
                int delCol[] = {0, 0, 1, -1};
                for (int i = 0; i < 4; i++) {
                    int newRow = delRow[i] + rowIndex;
                    int newCol = delCol[i] + colIndex;
                    if (isValid(newRow, newCol, grid.size(), grid[0].size()) &&
                        grid[newRow][newCol] == 1) {
                        grid[newRow][newCol]=2;
                        fresh--;
                        q.push({newRow, newCol});
                    }
                }
            }
            if(fresh==0) return steps;
            steps++;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return steps;
    }
};