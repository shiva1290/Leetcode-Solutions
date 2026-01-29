/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* DFS(TreeNode* root,TreeNode* p,TreeNode* q){
        if(!root || root==p || root==q){
            return root;
        }
        TreeNode* left=DFS(root->left,p,q);
        TreeNode* right=DFS(root->right,p,q);
        if(left==NULL){
            return right;
        }
        else if(right==NULL){
            return left;
        }
        else return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        return DFS(root,p,q);
    }
};