class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](auto&a, auto&b){
            return a[0]<b[0];
        });
        vector<int> curr={intervals[0][0],intervals[0][1]};
        vector<vector<int>>ans;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=curr[1]){
                curr[0]=min(curr[0],intervals[i][0]);
                curr[1]=max(intervals[i][1],curr[1]);
            }
            else {
                ans.push_back(curr);
                curr={intervals[i][0],intervals[i][1]};
            }
        }
        ans.push_back(curr);
        return ans;
    }
};