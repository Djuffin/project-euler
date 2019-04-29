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
    bool find_or_count(TreeNode* root, int k, int *val, int *count) {
        if (root == nullptr) {
            *count = 0;
            return false;
        }
        
        int left_val, left_count;
        if (find_or_count(root->left, k, &left_val, &left_count))  {
            *val = left_val;
            return true;
        }
        k -= left_count;
        if (k == 1) {
            *val = root->val;
            return true;
        }
        k--;
        
        int right_val, right_count;
        if (find_or_count(root->right, k, &right_val, &right_count)) {
            *val = right_val;
            return true;
        }
        
        *count = left_count + right_count + 1;
        return false;
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        int val = -1, count;
        find_or_count(root, k, &val, &count);
        return val;
    }
};