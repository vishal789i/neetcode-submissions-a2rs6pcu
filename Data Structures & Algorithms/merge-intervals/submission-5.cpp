class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for (auto& i : intervals) {
            if (res.empty()) {
                res.push_back(i);
            } else {
                if (res.back()[1] >= i[0]) {
                    res.back()[0] = min(res.back()[0], i[0]);
                    res.back()[1] = max(res.back()[1], i[1]);
                } else {
                    res.push_back(i);
                }
            }
        }

        return res;
    }
};
