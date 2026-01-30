class Solution {
public:
    void helper(int index,vector<int>&num,int count,int target,vector<vector<int>>&ans,vector <int> temp){
        if(index==num.size() || count==0){
            if(target==0 && count==0){
                ans.push_back(temp);
            }
            return;
        }
        if(target<0 || count<0){
            return;
        }
        temp.push_back(num[index]);
        helper(index+1,num,count-1,target-num[index],ans,temp);
        temp.pop_back();
        helper(index+1,num,count,target,ans,temp);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>num={1,2,3,4,5,6,7,8,9};
        vector<vector<int>>ans;
        vector<int>temp;
        helper(0,num,k,n,ans,temp);
        return ans;
    }
};