class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
         const int mod = 1e9 + 7;
        vector<vector<pair<int, int>>> adj(n);

        for (int i=0;i<roads.size();i++) {
            int u = roads[i][0], v = roads[i][1], t = roads[i][2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        vector<long long> distance(n, LLONG_MAX);
        vector<int> ways(n, 0);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        pq.push({0, 0});
        distance[0] = 0;
        ways[0] = 1;

        while (!pq.empty()) {
            auto [dis, curr] = pq.top();
            pq.pop();

            if (dis > distance[curr]) continue;

            for (auto [neighbor, weight] : adj[curr]) {
                long long newDist = dis + weight;

                if (newDist < distance[neighbor]) {
                    distance[neighbor] = newDist;
                    pq.push({newDist, neighbor});
                    ways[neighbor] = ways[curr];
                } 
                else if (newDist == distance[neighbor]) {
                    ways[neighbor] = (ways[neighbor] + ways[curr]) % mod;
                }
            }
        }

        return ways[n - 1] % mod;
    }
};