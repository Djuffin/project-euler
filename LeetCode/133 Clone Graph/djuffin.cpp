/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
   
    
    
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == nullptr) return nullptr;
        unordered_map<int, UndirectedGraphNode *> label2node;
        queue<UndirectedGraphNode *> q;
        q.push(node);
        label2node[node->label] = new UndirectedGraphNode(node->label);
        
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            
            auto new_node = label2node[node->label];
            for (auto neighbor : node->neighbors) {
                auto new_neighbor_i = label2node.find(neighbor->label);
                UndirectedGraphNode *new_neighbor;
                
                if (new_neighbor_i == label2node.end()) {
                    new_neighbor = new UndirectedGraphNode(neighbor->label);
                    label2node[neighbor->label] = new_neighbor;
                    q.push(neighbor);
                } else {
                    new_neighbor = new_neighbor_i->second;
                }
                
                new_node->neighbors.push_back(new_neighbor);
            }
        }
        
        return label2node[node->label];
    }
};