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
    int removeStones(vector<vector<int>> &stones) {
        int maxRow = 0, maxCol = 0;
        int N=0;
        for (auto &s : stones) {
            N++;
            maxRow = max(maxRow, s[0]);
            maxCol = max(maxCol, s[1]);
        }

        int offset = maxRow + 1;
        DisjointSet ds(offset + maxCol + 5);
        unordered_map<int, int> nodes;

        for (auto &it : stones) {
            int r = it[0];
            int c = it[1] + offset;
            ds.unionBySize(r, c);
            nodes[r] = 1;
            nodes[c] = 1;
        }

        int comp = 0;
        for (auto &p : nodes) {
            if (ds.findUPar(p.first) == p.first) comp++;
        }

        return N - comp;
    }
};