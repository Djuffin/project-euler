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
    int countLeft(TreeNode *root) {
        int result = 0;
        for (; root; root = root->left) {
            result++;
        }
        return result;
    }
    
    int countRight(TreeNode *root) {
        int result = 0;
        for (; root; root = root->right) {
            result++;
        }
        return result;
    }
    
    
    int countNodes(TreeNode* root, int knownLeft, int knownRight) {
        if (root == NULL) return 0;
        if (knownLeft == -1) knownLeft = countLeft(root);
        if (knownRight == -1) knownRight = countRight(root);
        if (knownRight == knownLeft) {
            return (1 << knownLeft) - 1;
        } else {
            return 1 + countNodes(root->left, knownLeft - 1, -1)
                     + countNodes(root->right, -1, knownRight - 1);
        }
    }   
    
    
public:
    int countNodes(TreeNode* root) {
        return countNodes(root, -1, -1);
    }
};