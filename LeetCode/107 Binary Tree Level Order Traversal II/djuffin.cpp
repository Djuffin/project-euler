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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        result.push_back({});
        
        queue<TreeNode *> q;
        q.push(root);
        q.push(nullptr);
        while (!q.empty()) {
            auto node = q.front(); q.pop();
            if (node == nullptr) {
                if (q.size() > 0) {
                    result.push_back({});
                    q.push(nullptr);
                }
            } else {
                result[result.size() - 1].push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};