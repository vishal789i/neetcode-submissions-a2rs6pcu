class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> counts(26);
        for (char ch : tasks) {
            counts[ch - 'A']++;
        }

        // i'll schedule the max occuring task first to minimize cpu intervals
        priority_queue<int> availableTasks;
        for (int i = 0; i < counts.size(); ++i) {
            if (counts[i] > 0) {
                availableTasks.push(counts[i]);
            }
        }

        // using queue to organize tasks in fifo
        queue<pair<int, int>> idleTasks;  // cnt, time at which to process again
        int t = 0;
        while (not availableTasks.empty() or not idleTasks.empty()) {
            t++;
            if (not availableTasks.empty()) {
                auto cnt = availableTasks.top();
                availableTasks.pop();
                cnt--;
                if (cnt > 0) {
                    idleTasks.push({cnt, t + n});
                }
                
            }

            if (not idleTasks.empty()) {
                auto [cnt, timeAvailable] = idleTasks.front();
                if (t == timeAvailable) {
                    availableTasks.push(cnt);
                    idleTasks.pop();
                }
            }
        }

        return t;
    }
};