
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double currSum=0;
        int firstNum=0;
        for(int i=0;i<k;i++){
            currSum+=nums[i];
        }
        double maxAns=currSum;
        for(int i=k;i<nums.size();i++){
            int sum=currSum-nums[firstNum]+nums[i];
            currSum=sum;
            if(sum>maxAns){
                maxAns=sum;
            }
            firstNum++;
        }

        return maxAns/k;
    }
};