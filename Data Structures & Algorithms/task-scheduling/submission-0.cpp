class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> counts(26, 0);
        for (auto task: tasks) {
            counts[task - 'A']++;
        }

        priority_queue<int> maxHeap;
        for (auto count: counts) {
            if (count > 0) {
                maxHeap.push(count);
            }
        }

        int time = 0;
        queue<pair<int, int>> q;
        while (not maxHeap.empty() or not q.empty()) {
            time++;

            if (not maxHeap.empty()) {
                int count = maxHeap.top();
                maxHeap.pop();
                if (count - 1 > 0) {
                    q.push({count - 1, time + n});
                }
            }

            if (not q.empty() and q.front().second == time) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};
