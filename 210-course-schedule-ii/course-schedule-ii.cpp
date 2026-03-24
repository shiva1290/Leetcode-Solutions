class Solution {
public:
    bool topoSort(int node, vector<vector<int>>& adj, vector<int>& ans,
                  vector<int>& visited) {
        visited[node]=true;
        for (auto it : adj[node]) {
            if (visited[it] == 0) {
                if(topoSort(it, adj, ans, visited)) return true;
            }
            else if(visited[it]==1){
                return true;
            }
        }
        visited[node] = 2;
        ans.push_back(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> visited(numCourses, 0);
        vector<int> ans;
        bool flag;
        for (int i=0;i<adj.size();i++) {
            if (visited[i] == 0) {
                if(topoSort(i, adj, ans, visited)){
                    return {};
                }
            }
        }
        reverse(ans.begin(), ans.end());
            return ans;
    }
};