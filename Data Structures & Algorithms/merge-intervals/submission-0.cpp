class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int i = 0, n = intervals.size();
        while (i < n) {
            if (res.empty()) {
                res.push_back(intervals[i]);
            } else {
                if (res.back()[1] >= intervals[i][0]) {
                    res.back()[0] = min(res.back()[0], intervals[i][0]);
                    res.back()[1] = max(res.back()[1], intervals[i][1]);
                } else {
                    res.push_back(intervals[i]);
                }
            }
            ++i;
        }

        return res;
    }
};