class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> char2freq;
        for (auto t : tasks) {
            char2freq[t]++;
        }

        priority_queue<int> maxHeap;
        for (auto [ch, freq] : char2freq) {
            maxHeap.push(freq);
        }

        queue<pair<int, int>> q;
        int t = 0;
        while (not maxHeap.empty() or not q.empty()) {
            t++;
            if (not maxHeap.empty()) {
                auto freq = maxHeap.top();
                maxHeap.pop();
                freq--;
                if (freq > 0) {
                    q.push({freq, t + n});
                }
            }

            if (not q.empty()) {
                auto [freq, time] = q.front();
                if (time == t) {
                    q.pop();
                    if (freq > 0) {
                        maxHeap.push(freq);
                    }
                }
            }
        }

        return t;
    }
};
