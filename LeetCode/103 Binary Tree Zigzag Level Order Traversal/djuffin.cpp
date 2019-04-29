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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> result;
        if (root == nullptr) return result;
        vector<TreeNode *> stack1, stack2;
        
        vector<TreeNode *> *current_stack = &stack1;
        vector<TreeNode *> *next_stack = &stack2;
        bool left_to_right = true;
        current_stack->push_back(root);
        
        while (!current_stack->empty())  {
            result.push_back(vector<int>());
            while(!current_stack->empty()) {
                auto node = current_stack->back();
                current_stack->pop_back();
                result.back().push_back(node->val);
                
                if (left_to_right) {
                    if (node->left)  next_stack->push_back(node->left);
                    if (node->right) next_stack->push_back(node->right);
                } else {
                    if (node->right) next_stack->push_back(node->right);
                    if (node->left)  next_stack->push_back(node->left);
                }
            }
            swap(current_stack, next_stack);
            left_to_right = !left_to_right;
        } 
        
        return result;
    }
};