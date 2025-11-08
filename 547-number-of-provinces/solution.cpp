class Solution {
public:
    void DFS(int i, vector<vector<int>>& adjList, vector<int>& vis) {
        vis[i] = 1;
        for (auto neighbour : adjList[i]) {
            if (!vis[neighbour]) {
                DFS(neighbour, adjList, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>> adj) {
        int V = adj.size();
        vector<vector<int>> adjList(V);
        for (int i = 0; i < adj.size(); i++) {
            for (int j = 0; j < adj.size(); j++) {
                if (adj[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        vector<int> vis(V, 0);
        int cnt = 0;

        for (int i = 0; i < adj.size(); i++) {
            if (!vis[i]) {
                cnt++;
                DFS(i, adjList, vis);
            }
        }
        return cnt;
    }
};