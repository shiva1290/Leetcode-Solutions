class Solution {
public:
    int dijkstra(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, k - 1});
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < times.size(); i++) {
            int parent = times[i][0] - 1;
            int neigh = times[i][1] - 1;
            int weight = times[i][2];
            adj[parent].push_back({neigh, weight});
        }

        vector<int> distance(n, 1e9);
        distance[k - 1] = 0;
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int node = p.second;
            int dist = p.first;
            for (auto it : adj[node]) {
                int distanceHere = it.second;
                if (dist + distanceHere < distance[it.first]) {
                    distance[it.first] = dist + distanceHere;
                    pq.push({distance[it.first], it.first});
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (distance[i] == 1e9)
                return -1;
            ans = max(ans, distance[i]);
        }
        return ans;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        return dijkstra(times, n, k);
    }
};