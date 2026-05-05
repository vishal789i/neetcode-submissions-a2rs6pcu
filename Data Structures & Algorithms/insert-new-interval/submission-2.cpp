class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0, n = intervals.size();
        // fast forward till new start < cur_end
        while (i < n and intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }

        // merge while cur_start <= new_end and cur_end >= new_start
        while (i < n and intervals[i][0] <= newInterval[1] and intervals[i][1] >= newInterval[0]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        res.push_back(newInterval);
        while (i < n) {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};

/*
1-----3
           4-------6
    2----------5
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
new 1--------------5
           cur 4-------6

xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
1----------------------6

*/
