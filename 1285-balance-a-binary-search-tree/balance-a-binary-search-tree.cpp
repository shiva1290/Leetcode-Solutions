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
class Solution {
public:
    void DFS(TreeNode* root,vector<int>&ans){
        if(!root){
            return;
        }
        DFS(root->left,ans);
        ans.push_back(root->val);
        DFS(root->right,ans);
        return;
    }
    TreeNode* build(vector<int>&ans,int low,int high){
        if(low>high) return nullptr;
        int mid=low+(high-low)/2;
        TreeNode* node=new TreeNode(ans[mid]);
        node->left=build(ans,low,mid-1);
        node->right=build(ans,mid+1,high);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>ans;
        DFS(root,ans);
        return build(ans,0,ans.size()-1);
    }
};