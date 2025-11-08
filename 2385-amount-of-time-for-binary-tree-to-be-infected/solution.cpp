class Solution {
public:
    void MapParents(TreeNode* root, map<TreeNode*, TreeNode*>& mpp) {
        if (!root)
            return;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
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
        }
        return;
    }

    TreeNode* DFS(TreeNode* root, int start) {
        if (root == nullptr) {
            return NULL;
        }
        if (root->val == start) {
            return root;
        }
        TreeNode* left = DFS(root->left, start);
        if (left)
            return left;

        TreeNode* right = DFS(root->right, start);
        return right;
    }

    int amountOfTime(TreeNode* root, int start) {
        int distance = 0;
        if (!root)
            return distance;
        map<TreeNode*, TreeNode*> mpp;
        MapParents(root, mpp);
        TreeNode* target = DFS(root, start);
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        visited.insert(target);
        q.push(target);


        while (!q.empty()) {
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
        return distance-1;
    }
};
