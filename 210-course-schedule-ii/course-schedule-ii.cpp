class Solution {
public:
    bool helper(int node, vector<vector<int>>& adj, stack<int>& st,
                vector<int>& visited) {
        visited[node] = 1;
        for (auto it : adj[node]) {
            if (visited[it] == 0) {
                if(helper(it, adj, st, visited)) return true;
            } else if (visited[it] == 1) {
                return true;
            }
        }
        visited[node] = 2;
        st.push(node);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            adj[u].push_back(v);
        }
        stack<int> st;
        vector<int> ans;
        vector<int> visited(numCourses, 0);
        for (int i = 0; i < adj.size(); i++) {
            if (visited[i] == 0) {
                if (helper(i, adj, st, visited)) {
                    return {};
                }
            }
        }
        while (!st.empty()) {
            int a = st.top();
            st.pop();
            ans.push_back(a);
        }
        return ans;
    }
};