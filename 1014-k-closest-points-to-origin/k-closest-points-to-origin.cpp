class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>,greater<pair<double,pair<int,int>>>> pq;
        for(auto p : points){
            double distance=sqrt((p[0]*p[0])+(p[1]*p[1]));
            pq.push({distance,{p[0],p[1]}});
        }
        vector<vector<int>>ans;
        for(int i=0;i<k;i++){
            auto node=pq.top();
            pq.pop();
            ans.push_back({node.second.first,node.second.second});
        }
        return ans;
    }
};