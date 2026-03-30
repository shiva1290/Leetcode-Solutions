class Solution {
public:
    vector<int> shortest(vector<vector<pair<int,int>>>&adj,int s){
        priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int>dist(adj.size(),1e5);
        dist[s]=0;
        pq.push({0,s});
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            int wt=p.first;
            int node=p.second;
            for(auto it : adj[node]){
                int currNode=it.first;
                int distanceHere=it.second;
                if(wt+distanceHere<dist[currNode]){
                    dist[currNode]=wt+distanceHere;
                    pq.push({dist[currNode],currNode});
                }
            }
        }
        return dist;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<times.size();i++){
            int u=times[i][0]-1;
            int v=times[i][1]-1;
            int wt=times[i][2];
            adj[u].push_back({v,wt});
        }
        vector<int>ans=shortest(adj,k-1);
        int finalAns=INT_MIN;
        for(auto n : ans){
            if(n==1e5) return -1;
            finalAns=max(n,finalAns);
        }
        return finalAns; 
    }
};