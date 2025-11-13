class DisjointSet {
   public:
    vector<int> size;
    vector<int> parent;

    DisjointSet(int N) {
        size.resize(N, 1);
        parent.resize(N);
        for (int i = 0; i < N; i++) {
            parent[i] = i;
        }
    }
    int findUPar(int n) {
        if (parent[n] == n) return n;
        return parent[n] = findUPar(parent[n]);
    }
    void unionBySize(int n, int m) {
        int ulp_u = findUPar(n);
        int ulp_v = findUPar(m);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] > size[ulp_v]) {
            parent[ulp_v] = parent[ulp_u];
            size[ulp_u] += size[ulp_v];
        } else {
            parent[ulp_u] = parent[ulp_v];
            size[ulp_v] += size[ulp_u];
        }
    }
};
class Solution {
   public:
    bool isValid(int r, int c, int n, int m) {
        if (r < 0 || r >= n) return false;
        if (c < 0 || c >= m) return false;
        return true;
    }
    void addInitial(vector<vector<int>>& grid, DisjointSet& ds) {
        int deltaRow[] = {1, -1, 0, 0};
        int deltaCol[] = {0, 0, 1, -1};
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) continue;
                for (int k = 0; k < 4; k++) {
                    int newRow = i + deltaRow[k];
                    int newCol = j + deltaCol[k];
                    if (isValid(newRow, newCol, n, m) &&
                        grid[newRow][newCol] == 1) {
                        int nodeNo = i * m + j;
                        int adjNo = newRow * m + newCol;
                        ds.unionBySize(nodeNo, adjNo);
                    }
                }
            }
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int deltaRow[] = {1, -1, 0, 0};
        int deltaCol[] = {0, 0, 1, -1};
        int n = grid.size();
        int m = grid[0].size();
        DisjointSet ds(n * m);
        addInitial(grid, ds);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) continue;

                set<int> nodes;
                for (int k = 0; k < 4; k++) {
                    int newRow = i + deltaRow[k];
                    int newCol = j + deltaCol[k];
                    if (isValid(newRow, newCol, n, m) &&
                        grid[newRow][newCol] == 1) {
                        int nodeNo = newRow * m + newCol;
                        nodes.insert(ds.findUPar(nodeNo));
                    }
                }
                int size = 0;
                for (auto it : nodes) {
                    size += ds.size[it];
                }
                ans = max(ans, size + 1);
            }
        }

        for (int cell = 0; cell < n * m; cell++) {
            ans = max(ans, ds.size[ds.findUPar(cell)]);
        }
        return ans;
    }
};
