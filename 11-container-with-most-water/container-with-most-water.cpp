class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea=INT_MIN;
        int area=1;
        int i=0;
        int j=height.size()-1;
        while(i<j){
            area=min(height[i],height[j])*(j-i);
            maxArea=max(area,maxArea);
            if(height[i]>height[j]){
                j--;
            }
            else i++;
        }
        return maxArea;
    }
};