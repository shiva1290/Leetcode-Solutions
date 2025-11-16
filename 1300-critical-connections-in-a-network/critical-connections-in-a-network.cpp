class Solution {
public:
    int timer = 1;

    void helperDFS(int node, int parent, vector<int> adj[], vector<int>& vis,
                   vector<int>& time, vector<int>& low,
                   vector<vector<int>>& bridges) {

        vis[node] = 1;
        time[node] = low[node] = timer++;

        for (auto it : adj[node]) {
            if (it == parent) continue;

            if (!vis[it]) {
                helperDFS(it, node, adj, vis, time, low, bridges);
                low[node] = min(low[node], low[it]);

                if (low[it] > time[node]) {
                    bridges.push_back({it, node});
                }
            } else {
                low[node] = min(low[node], time[it]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int V, vector<vector<int>>& E) {
        vector<int> adj[V];

        for (auto& it : E) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(V, 0), time(V), low(V);
        vector<vector<int>> bridges;

        helperDFS(0, -1, adj, vis, time, low, bridges);

        return bridges;
    }
};
