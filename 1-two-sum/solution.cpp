class Solution {

public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> arr;  // value, index
        for (int i = 0; i < nums.size(); i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());  // sort by value

        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int sum = arr[low].first + arr[high].first;
            if (sum == target) {
                return {arr[low].second, arr[high].second};
            }
            else if (sum < target) {
                low++;
            }
            else {
                high--;
            }
        }

        return {-1, -1}; // no pair found
    }
};
