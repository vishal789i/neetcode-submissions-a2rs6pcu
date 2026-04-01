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
        sort(intervals.begin(), intervals.end(), [] (auto&& i1, auto&& i2) {
            return i1.start < i2.start;
        });

        Interval& lastInterval = intervals[0];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start < lastInterval.end) {
                return false;
            }

            lastInterval = intervals[i];
        }

        return true;
    }
};
