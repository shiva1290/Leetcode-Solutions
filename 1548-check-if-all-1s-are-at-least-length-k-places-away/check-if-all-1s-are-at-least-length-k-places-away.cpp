class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int previous1 = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                continue;
            } else {
                if (previous1==-1) {
                    previous1 = i;
                    continue;
                }
                else if(i-previous1-1>=k){
                        previous1=i;
                    }
                else return false;
            }
        }
        return true;
    }
};