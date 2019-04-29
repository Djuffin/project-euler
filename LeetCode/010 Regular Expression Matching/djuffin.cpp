class Solution {
    vector<bool> expand(vector<bool> state, string p) {
        vector<bool> result;
        result.resize(state.size());
        queue<int> q;
        for (int i = 0; i < state.size(); i++) { 
            if (state[i]) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            if (result[i]) 
                continue;
                
            result[i] = true;
            
            bool current_star = (i < p.size()) && p[i] == '*';
            bool next_star = (i < p.size() - 1) && p[i + 1] == '*';
            
            if (current_star) {
                q.push(i + 1);
                q.push(i - 1);
            } else if (next_star) {
                q.push(i + 2);
            } 
        }
        return result;
    }
    
public:
    bool isMatch(string s, string p) {
        vector<bool> state;
        state.resize(p.size() + 1);
        state[0] = true;
        state = expand(state, p);
        for (auto c : s) {
            vector<bool> new_state;
            new_state.resize(state.size());
            for (int i = 0; i < state.size(); i++) {
                if (i >= p.size() || !state[i]) {
                    continue;
                }
                char pc = p[i];
                if (pc != '*' && (pc == '.' || pc == c)) {
                    new_state[i + 1] = true;
                }
            }
            state = expand(new_state, p);
        }    
        
        return state[p.size()];
    }
};