class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int canFlip=k;
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
        return maxOnes;
    }
};