class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
     unordered_map<int,int> count;
        count[0] = 1; 
        int prefix = 0, ans = 0;

        for(int x : nums) {
            prefix += x;
            int rem = (prefix % k + k) % k; 
            ans += count[rem];
            count[rem]++;
        }
        return ans;
    }
};