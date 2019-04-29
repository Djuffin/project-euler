/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval &l, const Interval &r) {
           return l.start < r.start; 
        });
        
        vector<Interval> result;
        for (int i = 0; i < intervals.size();) {
            auto &l = intervals[i];
            int j;
            for (j = i + 1; j < intervals.size(); j++) {
                auto &r = intervals[j];
                if (r.start <= l.end) {
                    l.end = max(r.end, l.end);
                } else {
                    break;
                }
            }
            i = j;
            result.push_back(l);
        }
        return result;
    }
};