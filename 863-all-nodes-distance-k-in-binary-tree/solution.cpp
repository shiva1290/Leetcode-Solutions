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
    void MapParents(TreeNode* root, map<TreeNode*, TreeNode*>& mpp) {
        if (!root)
            return;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                q.push(node->left);
                mpp[node->left] = node;
            }
            if (node->right) {
                q.push(node->right);
                mpp[node->right] = node;
            }
        }
        return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        map<TreeNode*, TreeNode*> mpp;
        if (!root)
            return ans;
        MapParents(root, mpp);
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);
        int distance = 0;

        while (!q.empty()) {
            if (distance == k) {
                while (!q.empty()) {
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                return ans;
            }
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left && visited.find(node->left) == visited.end()) {
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if (node->right && visited.find(node->right) == visited.end()) {
                    q.push(node->right);
                    visited.insert(node->right);
                }
                if (mpp.find(node) != mpp.end() &&
                    visited.find(mpp[node]) == visited.end()) {
                    q.push(mpp[node]);
                    visited.insert(mpp[node]);
                }
            }
            distance++;
        }
        return ans;
    }
};
