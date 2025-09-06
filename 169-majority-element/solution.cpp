class Solution {
public:
    int majorityElement(vector<int>& nums) {
    unordered_map<int, int> frequencyMap;
      int res = 0;
      int majority = 0;

        for (int n : nums) {
            frequencyMap[n]++;
            if (frequencyMap[n] > majority) {
                res = n;
                majority = frequencyMap[n];
            }
        }
        return res;
    }
};