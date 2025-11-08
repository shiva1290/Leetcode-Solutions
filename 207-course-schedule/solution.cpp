class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& arr) {
        vector<int>ans;
        vector<vector<int>> adj(V);
        vector<int>indegree(V);
        for(int i=0;i<arr.size();i++){
            int parent=arr[i][1];
            int node=arr[i][0];
            adj[parent].push_back(node);
        }
        for(int i=0;i<V;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }

        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return (ans.size()==V);
    }
};