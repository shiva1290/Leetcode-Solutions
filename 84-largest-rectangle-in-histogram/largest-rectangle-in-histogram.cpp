class Solution {
public:
    vector<int>nextSmaller(vector<int>& heights){   
        int n=heights.size();
        stack<int>st;
        vector<int>ans(n,-1);
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int>prevSmaller(vector<int>& heights){
        int n=heights.size();
        stack<int>st;
        vector<int>ans(n,-1);
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>nst=nextSmaller(heights);
        vector<int>pst=prevSmaller(heights);
        int maxArea=0;
        for(int i=0;i<heights.size();i++){
            int prevIndex=pst[i];
            int nextIndex=nst[i];
            if(nextIndex==-1)nextIndex=n;
            int area=heights[i]*(nextIndex-prevIndex-1);
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
};