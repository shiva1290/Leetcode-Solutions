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
    int DFS(TreeNode* root,bool &ans){
        if(!root) return -1;
        int left=1+DFS(root->left,ans);
        int right=1+DFS(root->right,ans);
        cout<<root->val<<" "<<left<<" "<<right<<"\n";
        if(abs(left-right)>1) ans=false;
        return max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        bool ans=true;
        DFS(root,ans);
        return ans;
    }
};