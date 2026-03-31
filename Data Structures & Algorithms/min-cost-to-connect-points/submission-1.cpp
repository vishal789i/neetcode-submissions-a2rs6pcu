class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        map<int, vector<pair<int, int>>> adj;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                auto &p1 = points[i], &p2 = points[j];
                auto x1 = p1[0], y1 = p1[1], x2 = p2[0], y2 = p2[1];
                auto w = abs(x1 - x2) + abs(y1 - y2);
                adj[i].push_back({w, j});
                adj[j].push_back({w, i});
            }
        }

        set<int> vis;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int res = 0;
        pq.push({0, 0});
        while (not pq.empty()) {
            auto [w1, n1] = pq.top();
            pq.pop();
            if (vis.contains(n1)) {
                continue;
            }
            
            res += w1;
            vis.insert(n1);
            for (auto [w2, n2] : adj[n1]) {
                pq.push({w2, n2});
            }
        }

        return res;
    }
};
