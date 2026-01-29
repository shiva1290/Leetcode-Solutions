class Solution {
public:
    int count=0;
    void DFS(int node, vector<vector<pair<int,int>>>& adj, vector<bool> &visited) {
        visited[node] = true;
        for (auto [neigh,needsReverse] : adj[node]) {
            if (!visited[neigh]) {
                count+=needsReverse;
                DFS(neigh, adj, visited);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<bool> visited(n, false);
        vector<vector<pair<int,int>>> adj(n);
        for (auto &nodes : connections) {
            int u = nodes[0];
            int v = nodes[1];
            adj[u].push_back({v,1});
            adj[v].push_back({u,0});
        }

        DFS(0, adj, visited);
        return count;
    }
};