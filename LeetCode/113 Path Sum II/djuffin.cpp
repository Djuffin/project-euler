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
    vector<vector<int>> result;
    void traverse(vector<int> &path, TreeNode *node, int sum) {
        path.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr) {
            if (sum == node->val) {
                result.push_back(path);
            }
        } else {
            if (node->left) {
                traverse(path, node->left, sum - node->val);
            } 
            if (node->right) {
                traverse(path, node->right, sum - node->val);
            }
        }
        path.pop_back();
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        result.clear();
        vector<int> path;
        if (root) {
            traverse(path, root, sum);
        }
        return result;
        
    }
};