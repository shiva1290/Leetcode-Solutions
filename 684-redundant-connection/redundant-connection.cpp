class DSU{
    public:
    vector<int>size;
    vector<int>parent;
    vector<int>cycle;
    DSU(int n){
        size.resize(n+1,1);
        parent.resize(n+1,1);
        for(int i=0;i<n+1;i++){
            parent[i]=i;
        }
    }
    bool find(int u,int v){
        return findParent(u)==findParent(v);
    }
    int findParent(int node){
        if(node==parent[node]){
             return node;
        }
        return parent[node]=findParent(parent[node]);
    }
    void unionBysize(int u,int v){
        int a=findParent(u);
        int b=findParent(v);
        if(a==b) {
        cycle={u,v};
        return;
        }
        if(size[a]<size[b]){
            parent[a]=b;
            size[b]+=size[a];
        }
        else {
            parent[b]=a;
            size[a]+=size[b];
        }
        return;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU DSU(edges.size());
        for(int i=0;i<n;i++){
            DSU.unionBysize(edges[i][0],edges[i][1]);
        }
        return DSU.cycle;
    }
};