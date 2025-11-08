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
    vector<vector<int>> levelOrder(TreeNode* root) {
          queue<TreeNode *> q;
        vector<vector<int>> ans;
        q.push(root);
        if(!root) return ans;
        while (!q.empty()) {
            int size = q.size();
            vector<int> res;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                res.push_back(node->val);

                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};