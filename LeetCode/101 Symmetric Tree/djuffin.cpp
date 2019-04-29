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
    bool isSymmetric(TreeNode* l, TreeNode* r) {
        if (l == r) return true;
        if (l == nullptr || r == nullptr) return false;
        if (l->val != r->val) return false;
        return isSymmetric(l->left, r->right) && isSymmetric(l->right, r->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return isSymmetric(root->left, root->right);
        
        
    }
};