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
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> events;
        for (auto& i : intervals) {
            events[i.start] ++;
            events[i.end] --;
        }

        int res = 0;
        int curMeetingRooms = 0;
        for (auto& [e, cnt] : events) {
            curMeetingRooms += cnt;
            res = max(res, curMeetingRooms);
        }

        return res;
    }
};
