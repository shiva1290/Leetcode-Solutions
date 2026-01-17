class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int cnt = 0;
        for(int i = 0; i < n;i++){
            if(nums[i]!= target[i]){
                if(mp.find(nums[i]) != mp.end())
                    mp[nums[i]]++;
                else {
                    cnt++;
                    mp[nums[i]]++;
                }
            }
        }
        return cnt;
    }
};