class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> preProd(n, 1);
        vector<int> sufProd(n, 1);
        
        for (int i = 1; i < n; i++) {
            preProd[i] = nums[i-1] * preProd[i - 1];
        }

        for (int i = n - 2; i >= 0; i--) {
            sufProd[i]*=nums[i+1]*sufProd[i+1];
        }
        vector<int>ans(n,1);
        for(int i=0;i<n;i++){
            ans[i]*=preProd[i]*sufProd[i];
        }
        return ans;
    }
};