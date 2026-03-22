class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int> ans(10001,-1);
        vector<int> finalans(n1,-1);
        stack<int>st;
        st.push(nums2[n2-1]);
        for(int i=n2-2;i>=0;i--){
            while(!st.empty() && st.top()<nums2[i]){
                st.pop();
            }
            if(!st.empty()) ans[nums2[i]]=st.top();
            st.push(nums2[i]);
        }
        for(int i=0;i<n1;i++){
            finalans[i]=ans[nums1[i]];
        }
        return finalans;
    }
};