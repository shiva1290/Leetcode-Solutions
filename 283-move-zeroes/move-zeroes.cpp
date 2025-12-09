class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k=0;
        int i=0;
        while(i<nums.size()){
            if(nums[i]!=0){
                swap(nums[i],nums[k]);
                k++;
            }
        i++;
        }
    }
};