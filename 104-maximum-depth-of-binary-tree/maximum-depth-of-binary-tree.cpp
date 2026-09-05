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
    int helper(TreeNode* root,int &maxHeight){
        if(!root) return 0;
        int left=0;
        int right=0;
        if(root->left) left=1+helper(root->left,maxHeight);
        if(root->right) right=1+helper(root->right,maxHeight);
        maxHeight=max(left,right);
        return max(left,right);
    }
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int maxHeight=0;
        helper(root,maxHeight);
        return 1+maxHeight;
    }
};