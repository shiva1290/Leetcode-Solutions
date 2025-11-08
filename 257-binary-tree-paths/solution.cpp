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
    void dfs(TreeNode* root, string res, vector<string>& s) {
        if (!root) {
            return;
        }
        res+=to_string(root->val);
        if (!root->left && !root->right) {
            s.push_back(res);
        } else {
            res+="->";
            dfs(root->left, res, s);
            dfs(root->right, res, s);
        }
        res.pop_back();
    }
        vector<string> binaryTreePaths(TreeNode * root) {
            vector<string> s;
            string r;
            dfs(root,r,s);
            return s;
        }
    };