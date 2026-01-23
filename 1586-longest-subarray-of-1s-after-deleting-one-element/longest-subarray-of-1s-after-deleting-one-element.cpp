class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int canFlip=1;
        int i=0;
        int j=0;
        int maxOnes=INT_MIN;
        while(j<n){
            if(nums[j]==0){
                canFlip--;
            }

            while(canFlip<0){
                if(nums[i]==0){
                    canFlip++;
                }
                i++;
            }
            maxOnes=max(maxOnes,j-i+1);
            j++;
        }
        return maxOnes-1;
    }
};