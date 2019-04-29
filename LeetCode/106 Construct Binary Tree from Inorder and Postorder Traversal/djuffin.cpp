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
    TreeNode *buildTree(int *postorder, int *inorder, int count) {
        if (count == 0) return nullptr;
        int *root_ptr = postorder + count - 1;
        
        auto result = new TreeNode(*root_ptr);
        auto mid_point = inorder;
        while (*mid_point != *root_ptr) {
            mid_point++;
        }
        
        int left_count = mid_point - inorder;
        result->left = buildTree(postorder, inorder, left_count);
        result->right = buildTree(postorder + left_count, mid_point + 1, count - left_count - 1);
        return result;
        
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(&*postorder.begin(), &*inorder.begin(), inorder.size());
    }
};
