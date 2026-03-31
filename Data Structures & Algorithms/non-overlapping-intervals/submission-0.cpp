class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int prevEnd = intervals[0][1], res = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            auto curStart = intervals[i][0];
            auto curEnd = intervals[i][1];
            if (curStart >= prevEnd) {
                prevEnd = curEnd;
            } else {
                res += 1;
                prevEnd = min(prevEnd, curEnd);
            }
        }

        return res;
    }
};
