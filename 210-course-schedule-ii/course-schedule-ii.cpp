class Solution {
public:
    bool topoSort(int node, vector<vector<int>>& adj, vector<int>& ans,
                 vector<int>& visited) {
        visited[node]=1;
        for (auto it : adj[node]) {
            if (visited[it] == 0) {
                if (topoSort(it, adj, ans, visited)) return true;
            }
            if (visited[it] == 1) {
                return true;
            }
        }
        visited[node] = 2;
        ans.push_back(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses + 1);
        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            adj[u].push_back(v);
        }
        vector<int> visited(numCourses + 1, 0);
        vector<int> ans;
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (topoSort(i, adj, ans, visited)) {
                    return {};
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};