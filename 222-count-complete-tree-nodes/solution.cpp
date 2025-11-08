class Solution {
   public:
    int countLeft(TreeNode* node) {
        if (!node) {
            return 0;
        }
        return 1+countLeft(node->left);
    }
    int countRight(TreeNode* node) {
        if (!node) {
            return 0;
        }
        return 1+countRight(node->right);
    }
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        int left=countLeft(root);
        int right=countRight(root);
        if(left==right){
            return (1 << left)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};