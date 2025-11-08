class Solution {
public:
 bool DFS(int node, vector<vector<int>>& adj, vector<int>& color) {
        for (auto neighbour : adj[node]) {
            if (color[neighbour] == -1) {
                color[neighbour] = !color[node];
                if (DFS(neighbour, adj, color) == false) {
                    return false;
                }
            } else if (color[neighbour] == color[node]) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& adj) {
        int V=adj.size();
        vector<int> color(V, -1), ans;
        int cycleLength = 0;
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (DFS(i, adj, color) == false) {
                    return false;
                };
            }
        }
        return true;
    }
};