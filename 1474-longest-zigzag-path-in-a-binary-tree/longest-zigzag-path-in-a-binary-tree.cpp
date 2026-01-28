/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
int maxPath=0;
    void DFS(TreeNode* root, int direction, int currLength) {
        if (!root) {
            return ;
        }
        maxPath=max(maxPath,currLength);
        if (direction == 1) {
            DFS(root->left, 0, currLength+1);
            DFS(root->right, 1, 1);
        }
        if (direction == 0) {
            DFS(root->right, 1, currLength+1);
            DFS(root->left, 0, 1);
        }
    }
    int longestZigZag(TreeNode* root) {
        DFS(root, 0, 0);
        DFS(root, 1, 0);
        return maxPath;
    }
};