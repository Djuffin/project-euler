/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *result = nullptr, *last = nullptr;
        
        //duplicate each node in the list
        for (auto node = head; node; node = node->next->next) {
            auto new_node = new RandomListNode(node->label);
            new_node->random = node->random;
            
            new_node->next = node->next;
            node->next = new_node;
        }
        
        // set random for copies to the copied of random :)
        for (auto node = head; node; node = node->next->next) {
            auto copy_node = node->next;
            copy_node->random = copy_node->random ? copy_node->random->next : nullptr;
        }
        
        // restore original list and build clone list
        for (auto node = head; node; node = node->next) {
            auto real_next = node->next->next;
            auto copy_node = node->next;
            
            copy_node->next = nullptr;
            if (result == nullptr) {
                last = result = copy_node;
            } else {
                last->next = copy_node;
                last = copy_node;
            }
            
            node->next = real_next;
        }
        
        
        return result;
    }
};