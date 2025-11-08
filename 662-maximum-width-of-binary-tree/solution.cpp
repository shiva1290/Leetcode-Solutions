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
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        if (!root)
            return ans;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int size = q.size();
            int index = q.front().second;
            int left = 0, right = 0;
            for (int i = 0; i < size; i++) {
                long long curr=q.front().second-index;
                TreeNode * node=q.front().first;
                q.pop();
                if (i == 0) {
                    left = curr;
                }
                if (i == size - 1) {
                    right = curr;
                }
                if (node->left) {
                    q.push({node->left, 2 * curr + 1});
                }
                if (node->right) {
                    q.push({node->right, 2 * curr + 2});
                }
            }
            ans = max(ans, right + 1);
        }
        return ans;
    }
};