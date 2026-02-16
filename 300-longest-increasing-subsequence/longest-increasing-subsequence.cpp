class Solution {
public:
    int lowerBound(int number, vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= number) {
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return low;
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> lenArray;
        lenArray.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (lenArray.back() < nums[i]) {
                lenArray.push_back(nums[i]);
            } else {
                int index = lowerBound(nums[i], lenArray);
                lenArray[index] = nums[i];
            }
        }
        return lenArray.size();
    }
};