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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *meet = NULL;
        
        
        while (fast) {
            fast = fast->next;
            if (fast) {
                fast = fast->next;
            }
            
            slow = slow->next;
            if (fast != NULL && fast == slow) {
                meet = fast;
                break;
            }
        }
        
        if (meet == NULL) {
            return nullptr;
        }
        
        ListNode *first = head;
        ListNode *second = meet;
        while (first != second) {
            first = first->next;
            second = second->next;
        }
        
        return first;        
    }
};