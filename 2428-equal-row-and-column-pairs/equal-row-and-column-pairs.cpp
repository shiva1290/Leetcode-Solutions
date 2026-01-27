class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        map<vector<int>, int> mpp;
        int total = 0;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                temp.push_back(grid[i][j]);
            }
            mpp[temp]++;
            temp.clear();
        }
        for (int j = 0; j < m; j++) {
            vector<int> temp;
            for (int i = 0; i < n; i++) {
                temp.push_back(grid[i][j]);
            }
            if (mpp[temp]) {
                total+=mpp[temp];
            }

            temp.clear();
        }
        return total;
    }
};