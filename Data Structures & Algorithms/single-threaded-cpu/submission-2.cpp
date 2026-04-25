class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pendingTasksHeap;  // eqT, procT, idx
        for (int i = 0; i < n; ++i) {
            pendingTasksHeap.push({tasks[i][0], tasks[i][1], i});
        }

        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> availableTasksHeap; // procT, idx
        int i = 0, t = 0;
        while (not pendingTasksHeap.empty() or not availableTasksHeap.empty()) {
            while (not pendingTasksHeap.empty()) {
                auto [eqT, procT, idx] = pendingTasksHeap.top();
                if (eqT > t) {
                    break;
                }

                pendingTasksHeap.pop();
                availableTasksHeap.push({procT, idx});
            }

            if (not availableTasksHeap.empty()) {
                auto [procT, idx] = availableTasksHeap.top();
                availableTasksHeap.pop();
                t += procT;
                res.push_back(idx);
            } else {
                auto [eqT, _, __] = pendingTasksHeap.top();
                t = eqT;
            }
        }

        return res;
    }
};