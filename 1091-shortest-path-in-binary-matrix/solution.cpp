class Solution {
public:
    bool isValid(int r, int c, int n, int m) {
        if (r < 0 || r >= n)
            return false;
        if (c < 0 || c >= m)
            return false;
        return true;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int deltaRow[] = {1, 0, -1, 0, 1, 1, -1, -1};
        int deltaCol[] = {0, 1, 0, -1, 1, -1, -1, 1};
        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1)
            return -1;
        pair<int, int> source = {0, 0};
        pair<int, int> destination = {n - 1, m - 1};

        queue<pair<int, pair<int, int>>> pq;

        vector<vector<int>> distance(grid.size(),
                                     vector<int>(grid[0].size(), 1e9));
        distance[source.first][source.second] = 0;
        pq.push({0, {source.first, source.second}});
        while (!pq.empty()) {
            auto node = pq.front();
            pq.pop();
            int dist = node.first;
            int row = node.second.first;
            int col = node.second.second;
        if(row==n-1 && col==m-1) return distance[n-1][m-1]+1;
            for (int i = 0; i < 8; i++) {
                int newRow = row + deltaRow[i];
                int newCol = col + deltaCol[i];
                if (isValid(newRow, newCol, n, m) &&
                    grid[newRow][newCol] == 0 &&
                    dist + 1 < distance[newRow][newCol]) {
                    pq.push({dist + 1, {newRow, newCol}});
                    distance[newRow][newCol] = dist + 1;
                }
            }
        }
        return -1;
    }
};