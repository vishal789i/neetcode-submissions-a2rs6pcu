class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for (int i = 0; i < tasks.size(); ++i) {
            tasks[i].push_back(i);
        }

        sort(tasks.begin(), tasks.end());
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        int i = 0, n = tasks.size();
        long long time = tasks[0][0];
        while (not minHeap.empty() or i < n) {
            while (i < n and time >= tasks[i][0]) {
                auto procTime = tasks[i][1], idx = tasks[i][2];
                minHeap.push({procTime, idx});
                i++;
            }

            if (minHeap.empty()) {
                time = tasks[i][0];
            } else {
                auto [procTime, idx] = minHeap.top();
                minHeap.pop();
                time += procTime;
                res.push_back(idx);
            }
        }

        return res;
    }
};