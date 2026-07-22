class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<tuple<int,int,int>> st;
      for(int i=0;i<nums.size();i++){
        int j=i+1;
        int k=nums.size()-1;
        while(j<=k && j!=k){
            if(nums[i]+nums[j]+nums[k]==0){
                st.insert({nums[i],nums[j],nums[k]});
                j++;
                k--;
            }
            else if(nums[i]+nums[j]+nums[k]>0){
                k--;
            }
            else j++;
        }
      }
      vector<vector<int>>ans;
      for(auto [first,second,third] : st){
        ans.push_back({first,second,third});
      }
      return ans;
    }
};