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
    struct comp {
        bool operator() (Interval& a, Interval& b) {
            return a.end > b.end;
        }
    };

    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [&] (auto& i1, auto& i2) {
            return i1.start < i2.start;
        });

        priority_queue<Interval, vector<Interval>, comp> minHeap;

        for (auto interval : intervals) {
            if (not minHeap.empty() and minHeap.top().end <= interval.start) {
                minHeap.pop();
            }

            minHeap.push(interval);
        }

        return minHeap.size();
    }
};
