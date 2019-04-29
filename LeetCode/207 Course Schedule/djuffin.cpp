class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
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
        
        while (!s.empty()) {
            int node = s.top().first;
            bool wayBack = s.top().second;
            if (wayBack) {
                s.pop();
                done[node] = true;
                //push to result
            } else {
                visited[node] = true;
                s.top().second = true;
                
                for (int d : node2nodes[node]) {
                    if (visited[d]) {
                        if (!done[d]) {
                            return false;
                        }
                    } else {
                        s.push({d, false});
                    }
                }
            }
        }
        return true;
    }
};