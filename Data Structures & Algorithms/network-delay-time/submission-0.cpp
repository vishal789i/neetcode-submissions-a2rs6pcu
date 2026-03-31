class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        map<int, vector<pair<int, int>>> vertex2AdjVerticesMap;
        for (auto time: times) {
            vertex2AdjVerticesMap[time[0]].push_back({time[1], time[2]});
        }

        // min heap based on wts pair<wt, destVertex>
        set<int> vis;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, k});
        int res = 0;
        while (not minHeap.empty()) {
            auto w1 = minHeap.top().first, n1 = minHeap.top().second;
            minHeap.pop();

            if (vis.count(n1)) {
                continue;
            }

            vis.insert(n1);
            res = w1;

            for (auto adjVertex: vertex2AdjVerticesMap[n1]) {
                auto n2 = adjVertex.first, w2 = adjVertex.second;
                if (vis.count(n2)) {
                    continue;
                }

                minHeap.push({w1 + w2, n2});
            }
        }

        return vis.size() == n ? res : -1;
    }
};
