class Solution {
public:
    void DFS(int node, vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[node] = true;
        cout<<node<<" ";
        int n=isConnected[node].size();
        for (int j = 0; j < n; j++)
        if (isConnected[node][j] == 1 && !visited[j]){
            DFS(j,isConnected,visited);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool>visited(n,false);
        int counter=0;
        for(int i=0;i<isConnected.size();i++){
            if(!visited[i]){
                counter++;
                DFS(i,isConnected,visited);
            }
        }
        return counter;
    }
};