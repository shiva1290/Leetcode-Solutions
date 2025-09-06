class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        int duplicate=0;

        for (int num : nums) {
            if (seen.count(num)) {
               duplicate=num;
            } else {
                seen.insert(num);
            }
        }

        return duplicate;
    }
};