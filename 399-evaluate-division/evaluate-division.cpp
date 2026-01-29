class Solution {
public:
    double dfs(int curr, int target, double product,
               vector<vector<pair<int,double>>>& adj,
               vector<bool>& visited) {
        if (curr == target) return product;

        visited[curr] = true;

        for (auto [neigh, val] : adj[curr]) {
            if (!visited[neigh]) {
                double res = dfs(neigh, target, product * val, adj, visited);
                if (res != -1.0) return res;
            }
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {

        unordered_map<string,int> id;
        int idx = 0;


        for (auto &eq : equations) {
            if (!id.count(eq[0])) id[eq[0]]=idx++;
            if (!id.count(eq[1])) id[eq[1]]=idx++;
        }

        vector<vector<pair<int,double>>> adj(idx);
     
        for (int i = 0; i < equations.size(); i++) {
            int u = id[equations[i][0]];
            int v = id[equations[i][1]];
            double val = values[i];
            adj[u].push_back({v, val});
            adj[v].push_back({u, 1.0 / val});
        }

        vector<double> ans;

        for (auto &q : queries) {
            if (!id.count(q[0]) || !id.count(q[1])) {
                ans.push_back(-1.0);
                continue;
            }

            if (q[0] == q[1]) {
                ans.push_back(1.0);
                continue;
            }

            vector<bool> visited(idx, false);
            ans.push_back(dfs(id[q[0]], id[q[1]], 1.0, adj, visited));
        }

        return ans;
    }
};
