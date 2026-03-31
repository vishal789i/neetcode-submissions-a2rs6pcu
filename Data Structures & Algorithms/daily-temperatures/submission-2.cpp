class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> stk; // index, temperature
        for (int i = 0; i < temperatures.size(); ++i) {
            while (not stk.empty() and stk.top().second < temperatures[i]) {
                auto pair = stk.top();
                stk.pop();
                res[pair.first] = i - pair.first;
            }
            stk.push({i, temperatures[i]});
        }
        return res;
    }
};
