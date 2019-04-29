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
    
    TreeNode *clone(TreeNode *root, int offset = 0) {
        if (root == nullptr) return root;
        auto result = new TreeNode(root->val + offset);
        result->left = clone(root->left, offset);
        result->right = clone(root->right, offset);
        return result;
    }
    
    TreeNode *add(TreeNode *root, TreeNode *node) {
        if (node == nullptr) 
            return root;
        if (root == nullptr) 
            return node;
        if (node->val < root->val) {
            root->left = add(root->left, node);
        } else {
            root->right = add(root->right, node);
        }
        return root;
    }
    
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>( { nullptr } );
        vector<vector<TreeNode*>> results(n + 1);
        results[0].push_back(nullptr);
        results[1].push_back(new TreeNode(1));
        
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                
                for (auto upper_tree: results[j]) {
                    for (auto bottom_tree: results[i - j - 1]) {
                        
                        auto tree = new TreeNode(i);
                        tree = add(clone(upper_tree, 0), tree);
                        tree = add(tree, clone(bottom_tree, j));
                        results[i].push_back(tree);
                        
                    }
                }
                
            }
        }
        return results[n];
        
    }
};