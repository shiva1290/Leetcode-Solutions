class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            matrix[u][v] = w;
            matrix[v][u] = w;
        }
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = 1e9;
                }
                if (i == j)
                    matrix[i][j] = 0;
            }
        }
        vector<int> reach(n, 0);
        for (int via = 0; via < matrix.size(); via++) {
            for (int i = 0; i < matrix.size(); i++) {
                for (int j = 0; j < matrix.size(); j++) {
                    matrix[i][j] =
                        min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                }
            }
        }
        int total = 0;
        int mini = INT_MAX;
        int minCity = -1;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                if (matrix[i][j] <= distanceThreshold && i != j) {
                    reach[i]++;
                }
                if (matrix[i][j] == 1e9) {
                    matrix[i][j] = -1;
                }
            }
            if (mini >= reach[i]) {
                mini = reach[i];
                minCity = i;
            }
        }
        return minCity;
    }
};