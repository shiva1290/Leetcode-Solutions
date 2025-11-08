class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& arr) {
          vector<int> indegree(V);
        vector<vector<int>> adj(V);

        for (int i = 0; i < arr.size(); i++) {
            adj[arr[i][1]].push_back(arr[i][0]);
        }
        
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int>ans;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (auto neighbours : adj[node]) {
                indegree[neighbours]--;
                if (indegree[neighbours] == 0) {
                    q.push(neighbours);
                }
            }
        }
        if(ans.size()<V){
            return {};
        }
        return ans;
    }
};