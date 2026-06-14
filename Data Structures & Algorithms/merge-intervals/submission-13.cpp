class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        map<int, int> events;
        for (auto& i : intervals) {
            events[i[0]]++;
            events[i[1]]--;
        }

        vector<vector<int>> res;
        int sum = 0, start = -1;
        for (auto [e, cnt] : events) {
            if (start == -1) {
                start = e;
            }

            sum += cnt;
            if (sum == 0) {
                res.push_back({start, e});
                start = -1;
            }
        }

        return res;
    }
};
