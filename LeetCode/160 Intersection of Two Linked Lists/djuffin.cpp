/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
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
    
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int countA = count(headA);
        int countB = count(headB);
        if (countA < countB) {
            swap(headA, headB);
            swap(countA, countB);
        }
        while (countA > countB) {
            countA--;
            headA = headA->next;
        }
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};