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
        map<int, int> events;
        for (auto& i : intervals) {
            events[i.start] += 1;
            events[i.end] -= 1;
        }

        int sum = 0;
        for (auto& [e, cnt] : events) {
            sum += cnt;
            if (sum > 1) {
                return false;
            }
        }

        return true;
    }
};


/*
0-----------------30
    5--10  15--20

*/