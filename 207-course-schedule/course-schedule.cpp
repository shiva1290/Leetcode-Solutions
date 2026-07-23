class Solution {
public:
    bool Topo(int x,vector<vector<int>>& nums,vector<int>&ans,vector<int>&visited){
        if(x>=nums.size()) return false;
        visited[x]=1;
        for(auto n : nums[x]){
            if(visited[n]==0){
                visited[n]=1;
                if(Topo(n,nums,ans,visited)) return true;
            }
            if(visited[n]==1) return true;
        }
        visited[x]=2;
        ans.push_back(x);
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& nums) {
        if(numCourses==1) return true;
        vector<vector<int>>adj(numCourses);
        for(auto it : nums){
            adj[it[0]].push_back(it[1]);
        }
        vector<int>ans;
        vector<int>visited(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(visited[i]==0){
                if(Topo(i,adj,ans,visited)) return false;
            }
        }   
        for(auto n : ans) cout<<n<<" ";
        return ans.size()==numCourses;
    }
};