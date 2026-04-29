class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int, int>> posSpeedPairs(n);
        for (int i = 0; i < n; ++i) {
            posSpeedPairs[i] = {position[i], speed[i]};
        }

        sort(posSpeedPairs.begin(), posSpeedPairs.end(), greater<>());
        stack<double> stk;
        for (auto [pos, speed] : posSpeedPairs) {
            auto t = (target - pos) / (speed * 1.0);
            if (stk.empty()) {
                stk.push(t);
            } else if (stk.top() < t) {
                stk.push(t);
            }
        }

        return stk.size();
    }
};