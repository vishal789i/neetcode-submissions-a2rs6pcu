class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        vector<pair<int, int>> events(n);
        for (auto& trip : trips) {
            auto numPass = trip[0], from = trip[1], to = trip[2];
            events.push_back({from, numPass});
            events.push_back({to, -numPass});
        }

        sort(events.begin(), events.end());
        int curCap = 0;
        for (auto& e: events) {
            curCap += e.second;
            if (curCap > capacity) {
                return false;
            }
        }

        return true;
    }
};