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
    int height(TreeNode *n) {
        if (n == nullptr) return 0;
        int hl = height(n->left);
        int hr = height(n->right);
        if (hl == -1 || hr == -1 || abs(hl - hr) > 1) return -1;
        return max(hl, hr) + 1;
    }
    
public:
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;    
    }
};