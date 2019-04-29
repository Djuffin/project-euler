struct Op {
    int pos, height;
    bool add;
};

static bool operator < (const Op &l, const Op& r) {
    return l.pos < r.pos;
}

class Solution {

public:    

    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<Op> ops;
        ops.reserve(buildings.size() * 2);
        for (auto &v: buildings) {
            ops.push_back( {.pos = v[0], .height = v[2], .add = true });
            ops.push_back( {.pos = v[1], .height = v[2], .add = false });
        }
        
        sort(ops.begin(), ops.end());
        multiset<int> heights;
        vector<pair<int, int>> result;
        Op prev_op = { .pos = INT_MIN } ;
        int prev_h = 0; 
        
        for (auto &op : ops) {
            if (op.pos != prev_op.pos) {
                int h =  heights.size() > 0 ? (*heights.rbegin()) : 0;
                if (h != prev_h) {
                    result.push_back({prev_op.pos, h});
                    prev_h = h;
                }
            }
     
            prev_op = op;            
            
            if (op.add) {
                heights.insert(op.height);    
            } else {
                heights.erase(heights.find(op.height));
            }
        }
        if (0 != prev_h) {
            result.push_back({prev_op.pos, 0});
        }
        
        return result;
        
    }
};