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
    int sum(TreeNode *node, int pre_total) {
        pre_total = pre_total * 10 + node->val;
        if (node->left == nullptr && node->right == nullptr) {
            return pre_total;
        }
        return
            (node->left ? sum(node->left, pre_total) : 0) +
            (node->right ? sum(node->right, pre_total) : 0);
    }
    
public:
    int sumNumbers(TreeNode* root) {
       if (root == nullptr) return 0;
       return sum(root, 0);
    }
};