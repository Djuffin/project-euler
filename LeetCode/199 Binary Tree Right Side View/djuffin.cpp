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
    int traverse(TreeNode *root, int depth, vector<int> *result) {
        if (root == 0) return 0;
        if (depth == 0) {
            result->push_back(root->val);
            int dr = traverse(root->right, 0, result);
            int dl = traverse(root->left, dr, result);
            return dr + dl + 1;
        } else {
            int dr = traverse(root->right, depth - 1, result);
            int dl = traverse(root->left, depth - 1 + dr, result);
            return dr + dl;
        }
    }
    
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        traverse(root, 0, &result);
        return result;
    }
};