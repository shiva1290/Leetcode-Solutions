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
    bool find(int u, int v) { return findUPar(u) == findUPar(v); }
    int findUPar(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = findUPar(parent[i]);
    }
    void unionBySize(int u, int v) {
        int ul_u = findUPar(u);
        int ul_v = findUPar(v);
        if (ul_u == ul_v) return;
        if (size[ul_u] < size[ul_v]) {
            parent[ul_u] = ul_v;
            size[ul_v] += size[ul_u];
        } else {
            parent[ul_v] = ul_u;
            size[ul_u] += size[ul_v];
        }
    }
};

class Solution {
   public:
    int makeConnected(int n, vector<vector<int>> &Edge) {
        DisjointSet ds (n);
        int cntExtras=0;
        for(auto it : Edge){
            int u=it[0];
            int v=it[1];
            if(ds.find(u,v)){
                cntExtras++;
            }
            else {
                ds.unionBySize(u,v);
            }
        }
        int cntC=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) cntC++;
        }
        int ans=cntC-1;
        if(cntExtras>=ans) return ans;
        return -1;
    }
};

