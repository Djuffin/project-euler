/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
struct HeapItem {
    ListNode *node;
    int list_index;
    
    HeapItem (ListNode *n, int i) {
        node = n;
        list_index = i;
    }
};

bool operator > (const HeapItem &left, const HeapItem &right)
{
    return left.node->val > right.node->val;
}
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = nullptr;
        ListNode *tail = nullptr;
        
        priority_queue<HeapItem, vector<HeapItem>, greater<HeapItem> > queue;
        
        for (int i = 0, size = lists.size(); i < size; i++)  {
            if (lists[i]) {
                queue.push(HeapItem(lists[i], i));
                lists[i] = lists[i]->next;
            }
        }
        
        while (!queue.empty()) {
            auto item = queue.top();
            queue.pop();
            
            if (head == nullptr) {
                tail = head = item.node;
            } else {
                tail->next = item.node;
                tail = item.node;
            }
            
            auto next_item = lists[item.list_index];
            if (next_item != nullptr) {
                lists[item.list_index] = next_item->next;
                queue.push(HeapItem(next_item, item.list_index));
            }
        }
        
        if (tail) {
            tail->next = nullptr;
        }
        
        return head;

    }
};