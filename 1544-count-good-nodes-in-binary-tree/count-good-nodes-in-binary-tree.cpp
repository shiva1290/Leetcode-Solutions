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
    void DFS(TreeNode* root,int Max,int &ans){
        if(!root){
            return;
        }
        if(root->val>=Max){
            Max=root->val;
            ans=ans+1;
        }
        DFS(root->left,Max,ans);
        DFS(root->right,Max,ans);
    }
    int goodNodes(TreeNode* root) {
        int ans=0;
        DFS(root,root->val,ans);
        return ans;
    }
};