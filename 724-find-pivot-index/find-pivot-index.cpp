class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return 0;

        vector<int> prefix(n, 0);
        vector<int> postfix(n, 0);

        prefix[0] = nums[0];
        postfix[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        for (int i = n - 2; i >= 0; i--) {
            postfix[i] = postfix[i + 1] + nums[i];
        }
        if (postfix[1] == 0)
            return 0;
        
        for (int i = 1; i < n - 1; i++) {
            if (prefix[i - 1] == postfix[i + 1]) {
                return i;
            }
        }

        if (prefix[n - 2] == 0)
            return n - 1;
            
        return -1;
    }
};