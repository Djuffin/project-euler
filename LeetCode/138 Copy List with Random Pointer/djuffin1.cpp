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
        unordered_map<RandomListNode *, RandomListNode *> map;
        map[nullptr] = nullptr;
        RandomListNode *result = nullptr, *last = nullptr;
        
        for (auto node = head; node; node = node->next) {
            auto new_node = new RandomListNode(node->label);
            new_node->random = node->random;
            map[node] = new_node;
            if (result == nullptr) {
                last = result = new_node;
            } else {
                last->next = new_node;
                last = new_node;
            }
        }
        
        for (last = result; last; last = last->next) {
            last->random = map[last->random];
        }
        
        return result;
    }
};