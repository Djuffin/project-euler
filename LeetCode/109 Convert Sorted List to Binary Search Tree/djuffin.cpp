/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    int count(ListNode *head) {
        int result = 0;
        while (head) {
            result++;
            head = head->next;
        }
        return result;
    }
    
    TreeNode *listToBst(ListNode *head, int len) {
        if (len == 0) return nullptr;
        if (len == 1) return new TreeNode(head->val);
        if (len == 2) {
            auto result = new TreeNode(head->val);
            result->right = new TreeNode(head->next->val);
            return result;
        }
        
        int midIndex = len / 2;
        auto pre_mid = head;
        for (int i = 0; i < midIndex - 1; i++) {
            pre_mid = pre_mid->next;    
        }
        auto mid = pre_mid->next;
        pre_mid->next = nullptr;
  
        auto result = new TreeNode(mid->val);
        result->left = listToBst(head, midIndex);
        result->right = listToBst(mid->next, len - midIndex - 1);
        return result;
    }
    
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return  listToBst(head, count(head));      
    }
};