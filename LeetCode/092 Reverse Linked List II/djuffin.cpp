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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        ListNode **revHeadPtr = &head;
        for (int i = 1; i < m; i++) {
            revHeadPtr = &((*revHeadPtr)->next);    
        }
        
        auto revHead = *revHeadPtr;
        *revHeadPtr = nullptr;
        ListNode *tailHead = revHead;
        for (int i = m; i <= n; i++) {
            auto tmp = revHead;
            revHead = revHead->next;
            tmp->next = *revHeadPtr;
            *revHeadPtr = tmp;
        }
        
        auto tail = revHead;
        while (tail) {
            tailHead->next = tail;
            tailHead = tail;
            tail = tail->next;
        }
        
        return head;
    }
};