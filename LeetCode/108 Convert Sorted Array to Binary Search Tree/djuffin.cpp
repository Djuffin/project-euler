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
    TreeNode* sortedArrayToBST(int *left, int *right) {
        if (left == right) return nullptr;
        int *mid = left + (right - left) / 2;
        auto result = new TreeNode(*mid);
        result->left = sortedArrayToBST(left, mid);
        result->right = sortedArrayToBST(mid + 1, right);
        return result;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(&*nums.begin(), nums.size() + &*nums.begin());
    }
};