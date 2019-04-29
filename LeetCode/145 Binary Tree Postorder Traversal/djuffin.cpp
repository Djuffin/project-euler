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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        stack<TreeNode *> stack;
        stack.push(root);
        while (!stack.empty()) {
            auto node = stack.top();
            if (node->right == nullptr && node->left == nullptr) {
                result.push_back(node->val);
                stack.pop();
            } 
            if (node->right) {
                stack.push(node->right);
                node->right = nullptr;
            }            
            if (node->left) {
                stack.push(node->left);
                node->left = nullptr;
            }
        }
        return result;
        
        
    }
};