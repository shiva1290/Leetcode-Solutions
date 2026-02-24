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
    void helper(TreeNode* root, int& sum, string bit) {
        if (!root) {
            return;
        }
        bit += to_string(root->val);
        if (!root->right && !root->left) {
            int number = stoi(bit, nullptr, 2);
            sum += number;
            return;
        }
        helper(root->left, sum, bit);
        helper(root->right, sum, bit);
        bit.pop_back();
    }

    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        string s;
        if (!root->left && !root->right)
            return root->val;
        helper(root, sum, s);
        return sum;
    }
};