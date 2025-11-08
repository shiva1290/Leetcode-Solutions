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
class NodeVal {
public:
    int maxNode,  minNode,  sum;
    NodeVal(int minNode, int maxNode, int sum) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->sum = sum;
    }
};
 class Solution {
public:
int maxSum=0;
    NodeVal helper(TreeNode* root) {
        if (!root) {
            return NodeVal(INT_MAX, INT_MIN, 0);
        }
        auto left = helper(root->left);
        auto right = helper(root->right);

        if (left.maxNode < root->val && root->val < right.minNode) {
            int currentSum = root->val + left.sum + right.sum;
            maxSum=max(maxSum,currentSum);
            return NodeVal(min(root->val, left.minNode),
                           max(root->val, right.maxNode), currentSum);
        }
        return NodeVal(INT_MIN,INT_MAX,max(left.sum,right.sum));
    }
    int maxSumBST(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};