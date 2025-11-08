class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
         srand(time(0));
        if (k > nums.size())
            return -1;
        int left = 0, right = nums.size() - 1;
        while (left<=right) {
            int pivotIndex = randomIndex(left, right);
            pivotIndex = partition(nums, pivotIndex, left, right);
            if (pivotIndex == k - 1)
                return nums[pivotIndex];
            else if (pivotIndex > k - 1)
                right = pivotIndex - 1;
            else
                left = pivotIndex + 1;
        }
        return -1;
    }
    int randomIndex(int left, int right) {
        int len = right - left + 1;
        return (rand() % len) + left;
    }
    int partition(vector<int>& nums, int pivotIndex, int left, int right) {
        int pivot = nums[pivotIndex];
        swap(nums[left], nums[pivotIndex]);

        int ind = left + 1;
        for (int i = left + 1; i <= right; i++) {
            if (nums[i] > pivot) {
                swap(nums[ind], nums[i]);
                ind++;
            }
        }
        swap(nums[left], nums[ind - 1]);
        return ind - 1;
    }
};