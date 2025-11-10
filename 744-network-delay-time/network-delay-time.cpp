class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &t : times)
            adj[t[0]-1].push_back({t[1]-1, t[2]});
        
        vector<int> dist(n, INT_MAX);
        dist[k-1] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k-1});

        while (!pq.empty()) {
            auto [dis, node] = pq.top();
            pq.pop();
            if (dis > dist[node]) continue;
            for (auto [neigh, wt] : adj[node]) {
                if (dis + wt < dist[neigh]) {
                    dist[neigh] = dis + wt;
                    pq.push({dist[neigh], neigh});
                }
            }
        }

        int ans = 0;
        for (int d : dist) {
            if (d == INT_MAX) return -1;
            ans = max(ans, d);
        }
        return ans;
    }
};
