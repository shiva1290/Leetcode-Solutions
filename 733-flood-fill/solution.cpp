class Solution {
public:
   bool isValid(int row, int col, int n, int m) {
        if (row < 0 || row >= n) return false;
        if (col < 0 || col >= m) return false;
        return true;
    }
    void BFS(int i, int j, vector<vector<int>> &image, vector<vector<int>> &vis,
             int newColor, int oldColor) {
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = 1;

        int n = image.size();
        int m = image[0].size();
        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            int row = node.first;
            int col = node.second;
            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};
            for (int k = 0; k < 4; k++) {
                int newRow = row + delRow[k];
                int newCol = col + delCol[k];

                if (isValid(newRow, newCol, n, m) &&
                    image[newRow][newCol] == oldColor && !vis[newRow][newCol]) {
                    vis[newRow][newCol] = 1;
                    image[newRow][newCol] = newColor;
                    q.push({newRow, newCol});
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                  int newColor) {
        int oldColor = image[sr][sc];
        if (oldColor == newColor) return image;
        int V = image.size();
        int n = image.size();
        int m = image[0].size();
        image[sr][sc]=newColor;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        BFS(sr, sc, image, vis, newColor, oldColor);
        return image;
    }
};