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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return NULL;
        
        //First I will search
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        
        } else {
        //If found
            if (!root->left) {
                TreeNode* temp = root->right;
                return temp;
            }

            if (!root->right) {
                TreeNode* temp = root->left;
                return temp;
            }
        //If it has both children
            TreeNode* succ = root->right;
            while(succ->left){
                succ=succ->left;
            }
            root->val = succ->val;
            root->right = deleteNode(root->right, succ->val);
        }

        return root;
    }
};