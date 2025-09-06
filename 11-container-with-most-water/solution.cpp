class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int right = n - 1;
        int left = 0;
        int area = 0;
        while (left < right) {
            area = max(area,min(height[right], height[left]) * (right - left));
            if(height[right]<height[left]) right--;
            else left++;
        }
        return area;
    }
};