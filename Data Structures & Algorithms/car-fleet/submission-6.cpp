class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; ++i) {
            pairs[i] = {position[i], speed[i]};
        }

        sort(pairs.begin(), pairs.end(), greater<>());
        vector<double> times;
        for (auto [pos, speed] : pairs) {
            auto t = (target - pos) / (speed * 1.0);
            if (times.empty()) {
                times.push_back(t);
            } else {
                if (times.back() < t) {
                    times.push_back(t);
                }
            }
        }

        return times.size();
    }
};
