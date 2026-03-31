class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        // monotonic decreasing stack
        vector<int> res(temps.size());
        stack<pair<int, int>> stk;
        for (int i = temps.size() - 1; i >= 0; --i) {
            while (not stk.empty() and temps[i] >= stk.top().first) {
                stk.pop();
            }

            if (not stk.empty()) {
                res[i] = stk.top().second - i;
            } else {
                res[i] = 0;
            }

            stk.push({temps[i], i});
        }

        return res;
    }
};