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
    pair<int64_t, int64_t> path(TreeNode* root) {
        if (root == nullptr) return {INT_MIN, INT_MIN};
        
        int64_t val = root->val;
        auto leftR = path(root->left);
        auto rightR = path(root->right);
        int64_t current = max(max(leftR.first + val, rightR.first + val), val);
        int64_t maximum = max(max(max(leftR.second, rightR.second), current), leftR.first + val + rightR.first);
        return {current, maximum};
    }
    
public:
    int maxPathSum(TreeNode* root) {
        return (int)path(root).second;
    }
};