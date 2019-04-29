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
    bool contains(TreeNode* root, TreeNode* p) {
        if (root == nullptr) {
            return false;
        }
        if (root->val > p->val) {
            return contains(root->left, p);
        }
        else if (root->val < p->val) {
            return contains(root->right, p);
        }
        else {
            return true;
        }
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       
        if (p->val > q->val) {swap(p,q);}
       
        if (root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        } 
        
        if (root->val < p->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        
        if (root->val == p->val && contains(root, q)) {
            return root;
        }
        
        if (root->val == q->val && contains(root, p)) {
            return root;
        }
        
        if (contains(root->left, p) && contains(root->right, q)) {
            return root;
        } 
        
        return false;
    }
};