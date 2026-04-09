class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                auto cost = abs(points[i][0] - points[j][0])
                          + abs(points[i][1] - points[j][1]);
                adj[i].push_back({cost, j});
                adj[j].push_back({cost, i});
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        minHeap.push({0, 0});
        vector<int> vis(n);
        int res = 0;
        while (not minHeap.empty()) {
            auto [cost, node] = minHeap.top();
            minHeap.pop();
            if (vis[node]) {
                continue;
            }

            vis[node] = 1;
            res += cost;
            for (auto [neiCost, nei] : adj[node]) {
                if (vis[nei]) {
                    continue;
                }

                minHeap.push({neiCost, nei});
            }
        }

        return res;
    }
};
