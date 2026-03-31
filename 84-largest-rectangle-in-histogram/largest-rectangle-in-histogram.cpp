class Solution {
public:
    vector<int>pse(vector<int>&heights){
        int n=heights.size();
        vector<int>ans(n,-1);
        stack<int>st;
        st.push(0);
        for(int i=1;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()) ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>nse(vector<int>&heights){
        int n=heights.size();
        vector<int>ans(n,n);
        stack<int>st;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()) ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>prev=pse(heights);
        vector<int>next=nse(heights);
        // for(auto num : prev){
        //     cout<<num<<" ";
        // }
        // cout<<"\n";
        // for(auto num : next){
        //     cout<<num<<" ";
        // }
        int maxArea=0;
        for(int i=0;i<heights.size();i++){
            maxArea=max(maxArea,(heights[i]*(next[i]-prev[i]-1)));
        }
        return maxArea;
    }
};