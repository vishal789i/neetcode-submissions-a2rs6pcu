class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<vector<int>> sortedTasks(n);
        for (auto i = 0; i < n; ++i) {
            sortedTasks[i] = {tasks[i][0], tasks[i][1], i};
        }

        sort(sortedTasks.begin(), sortedTasks.end());
        // 1,4,0  3,3,1  2,1,2
        // 1,4,0  2,1,2  3,3,1
        vector<int> res;
        int i = 0, t = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pendingTasks;
        while (i < n or not pendingTasks.empty()) {
            while (i < n and sortedTasks[i][0] <= t) {
                pendingTasks.push({sortedTasks[i][1], sortedTasks[i][2]});
                i++;
            }

            if (pendingTasks.empty()) {
                t = sortedTasks[i][0];
            } else {
                auto [procT, idx] = pendingTasks.top();
                pendingTasks.pop();
                t += procT;
                res.push_back(idx);
            }
        }

        return res;
    }
};