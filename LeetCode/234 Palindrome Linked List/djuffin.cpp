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
            head = head->next;
            result++;
        }
        return result;
    }
    
    ListNode *reverse(ListNode *head) {
        ListNode *new_head = nullptr;
        while (head) {
            auto next = head->next;
            head->next = new_head;
            new_head = head;
            head = next;
        }
        return new_head;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        int cnt = count(head);
        if (cnt <= 1) return true;
        auto half = head;
        
        for (int i = 0; i < cnt / 2 - 1; i++) {
            half = half->next;
        }
        
        ListNode *second_list;
        if (cnt % 2 == 1) {
            second_list = half->next->next;
        } else {
            second_list = half->next;
        }
        half->next = nullptr;
        
        second_list = reverse(second_list);
        while(second_list && head && second_list->val == head->val) {
            head = head->next;
            second_list = second_list->next;
        }
        
        return second_list == nullptr && head == nullptr;
    }
};