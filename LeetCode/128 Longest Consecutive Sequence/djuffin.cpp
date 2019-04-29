class Solution {
    
    //union find node
    struct Node {
        int parent;
        int count;
        int value;
        Node() {
            parent = count = value = 0;
        }
    };
    
    unordered_map<int, Node> value2node;
    
    Node *find_parent_node(int x) {
        auto it = value2node.find(x);
        if (it == value2node.end()) {
            return nullptr;
        }
        
        Node *result = &it->second;
        while (result->parent != result->value) {
            Node *next_result = &value2node[result->parent];
            result->parent = next_result->parent;
            result = next_result;
        }
        
        return result;
    }
    
public:
    int longestConsecutive(vector<int>& nums) {
        int maxCount = 0;
        for(int num: nums) {
            Node &node = value2node[num];
            if (node.count == 0) {
                node.count = 1;
                node.parent = node.value = num;
            } else {
                //duplicate, ignore it
                continue;
            }
            Node *merged_node = &node;
            Node *left_parent = find_parent_node(num - 1);
            if (left_parent != nullptr) {
                node.parent = left_parent->value;
                left_parent->count++;
                merged_node = left_parent;
            }
            
            Node *right_parent = find_parent_node(num + 1);
            if (right_parent != nullptr) {
                if (merged_node->count < right_parent->count) {
                    swap(merged_node, right_parent);
                }
                
                right_parent->parent = merged_node->parent;
                merged_node->count += right_parent->count;
            }
            
            if (merged_node->count > maxCount) {
                maxCount = merged_node->count;
            }
            
        }
        return maxCount;
    }
};