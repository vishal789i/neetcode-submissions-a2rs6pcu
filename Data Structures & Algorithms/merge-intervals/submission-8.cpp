class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals));
        vector<vector<int>> res;
        for (auto& i : intervals) {
            if (res.empty()) {
                res.push_back(i);
            } else {
                auto s = i[0], e = i[1];
                auto& prevInterval = res.back();
                if (prevInterval[1] >= s) {
                    prevInterval[1] = max(prevInterval[1], e);
                    prevInterval[0] = min(prevInterval[0], s);
                } else {
                    res.push_back(i);
                }
            }
        }

        return res;
    }
};
