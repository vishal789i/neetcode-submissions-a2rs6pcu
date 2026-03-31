/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.empty()) return true;
        sort(intervals.begin(), intervals.end(), [] (Interval& a, Interval& b) {
            return a.start < b.start;
        });
        Interval lastInterval = intervals[0];
        for (int i = 1; i < intervals.size(); ++i) {
            if (lastInterval.end > intervals[i].start) {
                return false;
            }
            lastInterval = intervals[i];
        }

        return true;
    }
};
