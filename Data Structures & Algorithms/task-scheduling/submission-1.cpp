class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> counts(26);
        for (auto t : tasks) {
            counts[t - 'A']++;
        }

        priority_queue<int> maxHeap;
        for (auto c : counts) {
            if (c > 0) {
                maxHeap.push(c);
            }
        }

        queue<pair<int, int>> q;
        int t = 0;
        while (not q.empty() or not maxHeap.empty()) {
            t++;
            if (not maxHeap.empty()) {
                auto cnt = maxHeap.top();
                maxHeap.pop();
                if (cnt - 1 > 0) {
                    q.push({cnt - 1, t + n});
                }
            }

            if (not q.empty()) {
                auto [cnt, time] = q.front();
                if (time == t) {
                    q.pop();
                    maxHeap.push(cnt);
                }
            }
        }

        return t;
    }
};
