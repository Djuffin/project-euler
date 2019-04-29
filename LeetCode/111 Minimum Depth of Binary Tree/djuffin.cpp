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
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int dl = minDepth(root->left);
        int dr = minDepth(root->right);
        if (dl == 0) return dr + 1;
        if (dr == 0) return dl + 1;
        return min(dl, dr) + 1;
    }
};