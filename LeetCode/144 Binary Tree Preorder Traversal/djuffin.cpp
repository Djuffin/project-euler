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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        stack<TreeNode *> stack;
        stack.push(root);
        while (!stack.empty()) {
            auto node = stack.top();
            stack.pop();
            result.push_back(node->val);
            
            if (node->right) {
                stack.push(node->right);
            }            
            if (node->left) {
                stack.push(node->left);
            }
        }
        return result;
        
        
    }
};