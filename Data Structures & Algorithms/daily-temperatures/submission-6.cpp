class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        stack<int> stk;
        for (int i = temperatures.size() - 1; i >= 0; --i) {
            while (not stk.empty() and temperatures[stk.top()] <= temperatures[i]) {
                stk.pop();
            }

            if (stk.empty()) {
                res[i] = 0;
            } else {
                res[i] = stk.top() - i;
            }

            stk.push(i);
        }

        return res;
    }
};
