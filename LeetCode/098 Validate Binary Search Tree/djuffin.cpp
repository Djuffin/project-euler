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
    bool valid(TreeNode* root, int64_t top, int64_t bottom) {
        if (root == nullptr) return true;
        if (root->val >= top || root->val <= bottom) return false;
        
        return valid(root->left, root->val, bottom) && valid(root->right, top, root->val);
        
    }
    
public:
    bool isValidBST(TreeNode* root) {
        return valid(root, LLONG_MAX, LLONG_MIN);
    }
};