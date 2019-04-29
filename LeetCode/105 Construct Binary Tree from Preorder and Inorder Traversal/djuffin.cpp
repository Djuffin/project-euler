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
    TreeNode *buildTree(int *preorder, int *inorder, int count) {
        if (count == 0) return nullptr;
        auto result = new TreeNode(*preorder);
        auto mid_point = inorder;
        while (*mid_point != *preorder) {
            mid_point++;
        }
        
        int left_count = mid_point - inorder;
        result->left = buildTree(preorder + 1, inorder, left_count);
        result->right = buildTree(preorder + left_count + 1, mid_point + 1, count - left_count - 1);
        return result;
        
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(&*preorder.begin(), &*inorder.begin(), inorder.size());
    }
};