class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        map<int, int> events;
        for (auto& i : intervals) {
            events[i[0]]++;
            events[i[1]]--;
        }

        vector<vector<int>> res;
        vector<int> interval;
        int have = 0;
        for (auto& [e, cnt] : events) {
            if (interval.empty()) {
                interval.push_back(e);
            }

            have += cnt;
            if (have == 0) {
                interval.push_back(e);
                res.push_back(interval);
                interval.clear();
            }
        }

        return res;
    }
};
