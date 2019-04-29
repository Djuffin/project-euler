/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    struct Entry{
        TreeNode *node;
        bool visited;
        Entry (TreeNode *n, bool v) {
            node = n;
            visited = v;
        }
    };
    
    stack<Entry> dfs;

public:
    BSTIterator(TreeNode *root) {
        if (root) {
            dfs.push({root, false});
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !dfs.empty();
    }

    /** @return the next smallest number */
    int next() {
        while (!dfs.empty()) {
            auto entry = dfs.top(); 
            dfs.pop();
            if (entry.visited) {
                return entry.node->val;
            } else {
                if (entry.node->right) dfs.push({entry.node->right, false});
                dfs.push({entry.node, true});
                if (entry.node->left) dfs.push({entry.node->left, false});
            }
        }
        assert(false);
        return -1;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
