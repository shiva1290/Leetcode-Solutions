class Solution {
public:
    int largest(vector<int>&nums){
        int n=nums.size();
        int pse=-1;
        int nse=n;
        int index=0;
        int area=0;
        int maxArea=INT_MIN;
        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
            nse=i;
            index=st.top();
            st.pop();
            pse=(st.empty()) ? -1 : st.top();
            area=nums[index]*(nse-pse-1);
            maxArea=max(maxArea,area);
            }
            st.push(i);
        }
        while(!st.empty()){
            nse=n;
            index=st.top();
            st.pop();
            pse=(st.empty()) ? -1 : st.top();
            area=nums[index]*(nse-pse-1);
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
     int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> psum(n,vector<int>(m, 0));

        int sum = 0;
        for (int c = 0; c < m; c++) {
            for (int r = 0; r < n; r++) {
                sum += matrix[r][c]-'0';
                if (matrix[r][c] == '0') {
                    sum = 0;
                }
                psum[r][c] = sum;
            }
            sum=0;
        }

        int maxArea = INT_MIN;
        for (int r = 0; r < n; r++) {
            maxArea = max(maxArea, largest(psum[r]));
        }
        return maxArea;   
    }
};