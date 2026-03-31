class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pendingHeap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> availableHeap;
        for (int i = 0; i < tasks.size(); ++i) {
            pendingHeap.push({tasks[i][0], tasks[i][1], i});
        }

        long long t = 0;
        vector<int> res;
        while (not pendingHeap.empty() or not availableHeap.empty()) {
            while (not pendingHeap.empty() and get<0>(pendingHeap.top()) <= t) {
                auto [eqT, procT, idx] = pendingHeap.top();
                pendingHeap.pop();
                availableHeap.push({procT, idx});
            }

            if (availableHeap.empty()) {
                t = get<0>(pendingHeap.top());
            } else {
                auto [procT, idx] = availableHeap.top();
                availableHeap.pop();
                t += procT;
                res.push_back(idx);
            }
        }

        return res;
    }
};