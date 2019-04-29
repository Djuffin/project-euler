/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

      ListNode* mergeTwoLists(ListNode *left, ListNode *right) {
        ListNode *head = NULL;
        ListNode *tail = NULL;
        
        while (left && right) {
            ListNode *node = NULL;
            if (left->val < right->val) {
                node = left;
                left = left->next;
            } else {
                node = right;
                right = right->next;
            }
            node->next = NULL;
            if (tail) {
                tail->next = node;
            } else {
                head = node;
            }
            tail = node;
        }
        
        ListNode *remainder = left ? left : right;
        if (tail) {
            tail->next = remainder;
        } else {
            tail = head = remainder;
        }
        
        return head;
        
    }
    
};