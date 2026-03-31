
class DSU{
    public:
    vector<int>size;
    vector<int>parent;
    vector<int>curr;
    DSU(int n){
        size.resize(n+1,1);
        parent.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    bool find(int a,int b){
        return (findParent(a)==findParent(b));
    }
    int findParent(int node){
        if(parent[node]==node){
            return parent[node];
        }
        return parent[node]=findParent(parent[node]);
    }
    void unionBySize(int a,int b){
        int parentA=findParent(a);
        int parentB=findParent(b);
        if(parentA==parentB) {
        curr={a,b};
        return;
        }
        if(size[parentA]<size[parentB]){
            parent[parentA]=parentB;
            size[parentB]+=size[parentA];
        } 
        else {
            parent[parentB]=parentA;
            size[parentA]+=size[parentB];
        }
        return;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU DSU(edges.size());
        for(int i=0;i<edges.size();i++){
            DSU.unionBySize(edges[i][0],edges[i][1]);
        }
        return DSU.curr;
    }
};