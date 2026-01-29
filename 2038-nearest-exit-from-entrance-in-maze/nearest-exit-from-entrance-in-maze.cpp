class Solution {
public:
    bool isValid(int row, int col, int n, int m) {
        if (row < 0 || row >= n)
            return false;
        if (col < 0 || col >= m)
            return false;
        return true;
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int, int>> q;
        vector<vector<int>> visited(maze.size(),
                                    vector<int>(maze[0].size(), -1));
        q.push({entrance[0], entrance[1]});
        visited[entrance[0]][entrance[1]] = 1;
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto node = q.front();
                q.pop();
                int rowIndex = node.first;
                int colIndex = node.second;
                if ((rowIndex == 0 || rowIndex == maze.size() - 1 ||
                     colIndex == 0 || colIndex == maze[0].size() - 1) &&
                    maze[rowIndex][colIndex] == '.' &&
                    (rowIndex != entrance[0] || colIndex != entrance[1])) {
                    return steps;
                }
                int delRow[] = {-1, 1, 0, 0};
                int delCol[] = {0, 0, 1, -1};
                for (int i = 0; i < 4; i++) {
                    int newRow = delRow[i] + rowIndex;
                    int newCol = delCol[i] + colIndex;
                    if (isValid(newRow, newCol, maze.size(), maze[0].size()) &&
                        maze[newRow][newCol] == '.' &&
                        visited[newRow][newCol] == -1) {
                        q.push({newRow, newCol});
                        visited[newRow][newCol] = 1;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};