class Solution {
public:
    void DFS(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        cout<<node<<" ";
        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                DFS(neigh, adj, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>dfsArray;
        vector<bool>visited(n,false);
        vector<vector<int>> adj(n);
        int counter=0;
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(isConnected[i][j]==1 && j>i){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i=0;i<adj.size();i++){
            if(!visited[i]){
                counter++;
                DFS(i,adj,visited);
            }
        }
        return counter;
    }
};