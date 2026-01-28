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
    void DFS(TreeNode* root,vector<int>& tree){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            tree.push_back(root->val);
        }
        DFS(root->left,tree);
        DFS(root->right,tree);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1;
        vector<int> tree2;
        DFS(root1,tree1);
        DFS(root2,tree2);
        return tree1==tree2;
    }
};