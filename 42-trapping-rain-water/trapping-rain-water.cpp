class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int leftMax = INT_MIN;
        int rightMax = INT_MIN;
        int totalArea = 0;
        while (left <= right) {
            if (height[left] < height[right]) {
                if (height[left] < leftMax) {
                    totalArea += leftMax - height[left];
                } else {
                    leftMax = height[left];
                }
                left++;
            } else {
                if (height[right] < rightMax) {
                    totalArea += rightMax - height[right];
                } else {
                    rightMax = height[right];
                }
                right--;
            }
        }
        return totalArea;
    }
};