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
    int maxLevelSum(TreeNode* root) {
        if (!root)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int maxSum = INT_MIN;
        int level=0;
        int currLevel=0;
        while (!q.empty()) {
            currLevel++;
            int s = q.size();
            int sum = 0;
            for (int i = 0; i < s; i++) {
                TreeNode* curr = q.front();
                q.pop();
                sum += curr->val;
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);

                if (i == s - 1) {
                   if(sum>maxSum){
                    maxSum=sum;
                    level=currLevel;
                   }
                }
            }
        }
        return level;
    }
};