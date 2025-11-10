class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0]-1;
            int v = times[i][1]-1;
            int w = times[i][2];
            adj[u].push_back({w,v});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int>distance(n,1e9);
        distance[k-1]=0;
        pq.push({0,k-1});
        while(!pq.empty()){
            auto fullNode=pq.top();
            pq.pop();
            int node=fullNode.second;
            int weight=fullNode.first;
            for(auto it : adj[node]){
                int weight=it.first;
                int neighbour=it.second;
                if(distance[node]+weight<distance[neighbour]){
                    distance[neighbour]=distance[node]+weight;
                    pq.push({distance[neighbour],neighbour});
                }
            }
        }
        int ans=0;
        for(auto num : distance){
            if(num==1e9) return -1;
            if(ans<num) ans=num;
        }
    return ans;
    }
};