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
        vector<pair<int, int>> events;
        for (auto& i : intervals) {
            events.push_back({i.start, 1});
            events.push_back({i.end, -1});
        }

        sort(events.begin(), events.end());
        int res = 0;
        int curMeetingRooms = 0;
        for (auto& [e, cnt] : events) {
            curMeetingRooms += cnt;
            res = max(res, curMeetingRooms);
        }

        return res;
    }
};
