class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [&] (auto&& a, auto&& b) {
            return a[1] < b[1];
        });

        // end, pass
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        int curPass = 0;
        for (auto t : trips) {
            auto pass = t[0], start = t[1], end = t[2];
            while (not minHeap.empty()) {
                auto [heapEnd, heapPass] = minHeap.top();
                if (heapEnd > start) {
                    break;
                }
                
                minHeap.pop();
                curPass -= heapPass;
            }

            curPass += pass;
            if (curPass > capacity) {
                return false;
            }

            minHeap.push({end, pass});
        }

        return true;
    }
};