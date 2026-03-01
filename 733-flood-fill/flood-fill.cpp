class Solution {
public:
    bool isValid(int row, int col, int colSize, int rowSize) {
        if (row < 0 || row >= rowSize)
            return false;
        if (col < 0 || col >= colSize)
            return false;
        return true;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>>visited(n,vector<int>(m,-1));
        int original = image[sr][sc];
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        int delRow[] = {1, -1, 0, 0};
        int delCol[] = {0, 0, -1, 1};
        visited[sr][sc]=1;
        while (!q.empty()) {
            auto a = q.front();
            q.pop();
            int row = a.first;
            int col = a.second;
            visited[row][col]=1;
            for (int i = 0; i < 4; i++) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];
                if (isValid(newRow, newCol, m, n) && visited[newRow][newCol]!=1) {
                    if (image[newRow][newCol] == original) {
                        image[newRow][newCol] = color;
                        q.push({newRow, newCol});
                    }
                }
            }
        }
        return image;
    }
};