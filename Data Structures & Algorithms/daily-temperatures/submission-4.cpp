class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res;
        stack<pair<int, int>> stk;
        for (int i = temperatures.size() - 1; i >= 0; --i) {
            while (not stk.empty() and stk.top().first <= temperatures[i]) {
                stk.pop();
            }

            if (stk.empty()) {
                res.push_back(0);
            } else {
                res.push_back(stk.top().second - i);
            }

            stk.push({temperatures[i], i});
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
