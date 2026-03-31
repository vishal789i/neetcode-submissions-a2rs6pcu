class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [&] (auto& a, auto& b) {
            return a[1] < b[1];
        });

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap; // end, numPass

        int curPass = 0;
        for (auto& t : trips) {
            auto numPass = t[0], start = t[1], end = t[2];
            while (not minHeap.empty()) {
                if (minHeap.top().first <= start) {
                    curPass -= minHeap.top().second;
                    minHeap.pop();
                } else {
                    break;
                }
            }

            curPass += numPass;
            if (curPass > capacity) {
                return false;
            }

            minHeap.push({end, numPass});
        }

        return true;
    }
};