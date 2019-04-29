/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == nullptr) return;
        TreeLinkNode *child = nullptr, *first_child = nullptr;
        for (auto current = root; current != nullptr; current = current->next) {
            if (current->left != nullptr) {
                if (child == nullptr) {
                    first_child = child = current->left;
                } else {
                    child->next = current->left;
                    child = child->next;
                } 
            }
            
            if (current->right != nullptr) {
                if (child == nullptr) {
                    first_child = child = current->right;
                } else {
                    child->next = current->right;
                    child = child->next;
                } 
            }
        }
        connect(first_child);
    }
};