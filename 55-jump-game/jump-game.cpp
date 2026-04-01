class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        int maxReach=0;
        for(int i=0;i<nums.size();i++){
           int farthest=i+nums[i];
            if(maxReach<i){
                return false;
            }
            if(maxReach==nums.size()-1) return true;
            maxReach=max(maxReach,farthest);
        }
        return true;
    }
};