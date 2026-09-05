class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(auto n : nums){
            if(mpp.find(n)!=mpp.end()) return true;
            mpp[n]=1;
        }
        return false;
    }
};