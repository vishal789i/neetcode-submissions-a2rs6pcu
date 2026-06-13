class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnts(26);
        for (auto t : tasks) {
            cnts[t - 'A']++;
        }

        priority_queue<int> pq;
        for (auto c : cnts) {
            if (c > 0) {
                pq.push(c);
            }
        }

        queue<pair<int, int>> q; // cnt, time
        int t = 0;
        while (not pq.empty() or not q.empty()) {
            t++;
            if (not pq.empty()) {
                auto cnt = pq.top();
                pq.pop();
                if (--cnt) {
                    q.push({cnt, t + n});
                }
            }

            if (not q.empty() and q.front().second == t) {
                auto cnt = q.front().first;
                q.pop();
                pq.push(cnt);
            }
        }

        return t;
    }
};
