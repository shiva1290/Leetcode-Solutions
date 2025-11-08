class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int area = 0;
        int maxArea = INT_MIN;
        stack<int> st;
        int nse = heights.size();
        int pse = -1;
        int index;
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                index = st.top();
                nse = i;
                st.pop();
                pse = (st.empty()) ? -1 : st.top();
                int area = heights[index] * (nse - pse - 1);
                maxArea = max(area, maxArea);
            }
            st.push(i);
        }
        while (!st.empty()) {
            index = st.top();
            nse = heights.size();
            st.pop();
            pse = (st.empty()) ? -1 : st.top();
            int area = heights[index] * (nse - pse - 1);
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};