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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode *> s;
        if (root) {
            s.push(root);
        }
        vector<int> result;
        
        while (!s.empty()) {
            auto node = s.top(); s.pop();
            if (node->left) {
                auto l = node->left;
                node->left = nullptr;
                s.push(node);
                s.push(l);
            } else {
                result.push_back(node->val);
                if (node->right) {
                    s.push(node->right);
                }
            }
        }
        
        return result;
    }
};