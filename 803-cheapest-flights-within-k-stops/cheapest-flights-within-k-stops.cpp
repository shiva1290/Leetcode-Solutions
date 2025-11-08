#define P pair<int, pair<int, int>>
class Solution {
   public:
    int findCheapestPrice(int V, vector<vector<int>> &flights, int src, int dst,
                       int K) {
        vector<vector<pair<int, int>>> adj(V);
        for (int i = 0; i < flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            adj[u].push_back({v, w});
        }
        vector<int> minDist(V, 1e9);
        minDist[src] = 0;
        queue<P> q;
        q.push({0, {src, 0}});

        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int stops = p.first;
            int node = p.second.first;
            int dist = p.second.second;
            if (stops > K) continue;
            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edgeWt = it.second;
                if (dist + edgeWt < minDist[adjNode] && stops <= K) {
                    minDist[adjNode] = dist + edgeWt;
                    q.push({stops + 1, {adjNode, minDist[adjNode]}});
                }
            }
        }
        if(minDist[dst]==1e9) return -1;
        return minDist[dst];
    }
};

