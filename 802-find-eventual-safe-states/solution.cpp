class Solution {
    public:
    // bool DFS(int node, vector<vector<int>>& adj, vector<int> &vis,
    //              vector<int> &pathvis, vector<int> &check) {
    //         vis[node] = 1;
    //         pathvis[node] = 1;
    //         for (auto it : adj[node]) {
    //             if (pathvis[it]) {
    //                 check[node];
    //                 return true;
    //             } else if (!vis[it]) {
    //                 if (DFS(it, adj, vis, pathvis,check)) {
    //                     check[node];
    //                     return true;
    //                 };
    //             }
    //         }
    //         pathvis[node] = false;
    //         check[node] = 1;
    //         return false;
    //     }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V = adj.size();
        int W=adj[0].size();
        vector<int> ans;
        vector<int> indegree(V, 0);
        vector<vector<int>> revAdj(V);

        for (int i = 0; i < V; i++) {
            for (auto nodes : adj[i]) {
                revAdj[nodes].push_back(i);
                indegree[i]++;
            }
        }
        queue<int>q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto neighbour : revAdj[node]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};