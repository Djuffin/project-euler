class Solution {
    typedef vector<unsigned int> fingerprint;
    fingerprint calc_fingerprint(const string &s) {
        vector<unsigned int> counts(256);
        for (auto c : s) {
            counts[c]++;
        }
        fingerprint result;
        for (unsigned int i = 0; i < counts.size(); i++) {
            if (counts[i] > 0) {
                result.push_back((i << 24) | counts[i]);
            }
        }
        return result;
    }
    
    struct Hasher {
        size_t operator () (const fingerprint &v) const {
            size_t result = 0;
            for (auto &p : v) {
                result *= 31;
                result += p;
            }
            return result;
        }
    };
    
public:
    vector<string> anagrams(vector<string>& strs) {
        unordered_map<fingerprint, vector<string *>, Hasher> map;
        for (auto &s: strs) {
            map[calc_fingerprint(s)].push_back(&s);
        }
        vector<string> result;
        result.reserve(strs.size());
        for (auto &kv : map) {
            if (kv.second.size() > 1) {
                for (string *s: kv.second) {
                    result.push_back(*s);
                }
            }
        }
        return result;
        
    }
};