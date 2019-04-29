class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        //counting sort
        vector<int> counts(citations.size() + 1);
        for (auto c : citations) {
            if (c > citations.size()) {
                counts.back()++;
            } else {
                counts[c]++;
            }
        }
        
        int last = 0;
        for (int i = 0; i < counts.size(); i++) {
            for (int j = 0; j < counts[i]; j++) {
               citations[last++] = i;
            }
        }
        
        int i;
        for (i = 1; i <= citations.size(); i++) {
            if (citations[citations.size() - i] < i) {
                break;
            }
        }
        
        return i - 1;
        
    }
};