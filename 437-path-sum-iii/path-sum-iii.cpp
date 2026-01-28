/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
using ll=long long;
class Solution {
public:
    void DFS(TreeNode* root,int targetSum,int &ans,ll currSum,unordered_map<long long,int> & mpp){
        if(!root){
            return;
        }
        currSum+=root->val;
        if(mpp[currSum - targetSum]){
            ans+=mpp[currSum-targetSum];
        }
        mpp[currSum]++;
        cout<<currSum<<" ";
        DFS(root->left,targetSum,ans,currSum,mpp);
        DFS(root->right,targetSum,ans,currSum,mpp);
        mpp[currSum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        int ans=0;
        ll currSum=0;
        unordered_map<long long,int> mpp;
        mpp[0]=1;
        DFS(root,targetSum,ans,currSum,mpp);
        return ans;
    }
};