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
     public:
       int maxSum(TreeNode*root, int & sum){
        if(!root) return 0;
        int left=max(0,maxSum(root->left,sum));
        int right=max(0,maxSum(root->right,sum));
        sum=max(sum,left+right+root->val);
        return root->val+max(left,right);
       }
        int maxPathSum(TreeNode* root) {
            int sum=INT_MIN;
            maxSum(root, sum);
            return sum;
        }
};