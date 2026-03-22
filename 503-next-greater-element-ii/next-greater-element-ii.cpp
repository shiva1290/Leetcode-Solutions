class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>n1=nums;
        for(auto n : nums){
            n1.push_back(n);
        }

        stack<pair<int,int>>st;
        int n2=n1.size();
        st.push({n1[n2-1],n2-1});
        vector<int>ans(n2,-1);

        for(int i=n2-1;i>=0;i--){
            while(!st.empty() && st.top().first<= n1[i]){
                st.pop();
            }
            if(!st.empty() && st.top().second%n!=i%n) ans[i]=st.top().first;
            st.push({n1[i],i});
        }
        ans.resize(n);
        return ans;
    }
};