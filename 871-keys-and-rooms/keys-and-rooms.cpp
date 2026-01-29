class Solution {
public:
void DFS(int node, vector<vector<int>>& adj, vector<bool>& visited,vector<int>& dfsArray) {
    visited[node] = true;
    dfsArray.push_back(node);
    for (int neigh : adj[node]) {
        if (!visited[neigh]) {
            DFS(neigh, adj, visited,dfsArray);
        }
    }
}

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>dfsArray;
        vector<bool>visited(n,false);
        DFS(0,rooms,visited,dfsArray);
        return (dfsArray.size()==n);
    }
};