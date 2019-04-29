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
public:
    void flatten(TreeNode* root) {
        stack<TreeNode *> s;
        if (root)
            s.push(root);
        TreeNode *last = nullptr;
        while (!s.empty()) {
            auto node = s.top(); s.pop();
            if (last != nullptr) {
                last->left = nullptr;
                last->right = node;
            }
            last = node;
            if (last->right) {
                s.push(last->right);
            }
            if (last->left) {
                s.push(last->left);
            }
        }
        
    }
};