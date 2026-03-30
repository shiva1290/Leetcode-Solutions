class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n==1) return intervals;
        sort(intervals.begin(),intervals.end(),[](auto&a,auto&b){
            return a[0]<b[0];
        });
        vector<vector<int>>ans;
        vector<int>curr={intervals[0][0],intervals[0][1]};
        for(int i=1;i<intervals.size();i++){
            if(curr[1]>=intervals[i][0]){
                curr={curr[0],max(curr[1],intervals[i][1])};
            }
            else {
            ans.push_back(curr);
            curr=intervals[i];
            }
        }
        ans.push_back(curr);
        return ans;
    }
};