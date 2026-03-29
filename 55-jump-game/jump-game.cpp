class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        int maxReach=0;
        for(int i=0;i<nums.size()-1;i++){
            if (i > maxReach) return false;
            int farthest=nums[i]+i;
            maxReach=max(maxReach,farthest);
            if(maxReach>=nums.size()-1){
                return true;
            }
        }
        return false;
    }
};