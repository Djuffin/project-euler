class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> node2nodes;    
        node2nodes.resize(numCourses);
        
        vector<bool> visited;
        visited.resize(numCourses);
        
        vector<bool> done;
        done.resize(numCourses);
        
        for (auto p: prerequisites) {
           node2nodes[p.second].push_back(p.first);
        }
        stack<pair<int, bool>> s;
        for (int i = 0; i < numCourses; i++) {
            s.push({i, false});
        }
        vector<int> result;
        
        while (!s.empty()) {
            int node = s.top().first;
            bool wayBack = s.top().second;

            if (wayBack) {
                s.pop();
                done[node] = true;
                result.push_back(node);
            } else {
                if (visited[node]) {
                    if (!done[node]) {
                        return vector<int>();
                    }
                    s.pop();
                } else {                
                    s.top().second = true;
                    visited[node] = true;                    
                    for (int d : node2nodes[node]) {
                        s.push({d, false});
                    }
                }
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};