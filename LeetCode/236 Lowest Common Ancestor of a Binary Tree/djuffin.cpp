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
    bool contains(TreeNode *root, TreeNode *a) {
        if (root == nullptr) return false;
        if (root == a) return true;
        return contains(root->left, a) || contains(root->right, a);
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        
        if (root == p) {
            if (contains(root->left, q) || contains(root->right, q)) {
                return root;
            } else {
                return nullptr;
            }
        }
        
        if (root == q) {
            if (contains(root->left, p) || contains(root->right, p)) {
                return root;
            } else {
                return nullptr;
            }
        }
        
        auto fromLeft = lowestCommonAncestor(root->left, p, q);
        if (fromLeft) {
            return fromLeft;
        }
        
        auto fromRight = lowestCommonAncestor(root->right, p, q);
        if (fromRight) {
            return fromRight;
        }
        
        if (contains(root->left, p) && contains(root->right, q)) {
            return root;
        }
        
        if (contains(root->left, q) && contains(root->right, p)) {
            return root;
        }
        
        return nullptr;
    }
};