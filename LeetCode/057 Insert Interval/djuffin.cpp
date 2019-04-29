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
    int binary_search(Interval *left, Interval *right, int start) {
        if (left == right) return 0;
        auto original_left = left;
        while (left != right) {
            auto mid = left + (right - left) / 2;
            if (mid->start < start) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (left > original_left) {
            auto prev = left - 1;
            if (prev->end >= start) {
                left = prev;
            }
        }
        return left - original_left;
    }
    
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int n = intervals.size();
        Interval *end = n + &*intervals.begin();
        auto insert_point = binary_search(&*intervals.begin(), end, newInterval.start);
        int count = 0;
        for (; insert_point + count < n && intervals[insert_point + count].start <= newInterval.end; count++);
        
        if (insert_point < n && intervals[insert_point].start < newInterval.start) {
            newInterval.start = intervals[insert_point].start;
        }
        if (count != 0 && intervals[insert_point + count - 1].end > newInterval.end) {
            newInterval.end = intervals[insert_point + count - 1].end;
        }
        if (count != 0) {
            intervals.erase(intervals.begin() + insert_point, intervals.begin() + insert_point + count);
        }
        intervals.insert(intervals.begin() + insert_point, newInterval);
        return intervals;
    }
};