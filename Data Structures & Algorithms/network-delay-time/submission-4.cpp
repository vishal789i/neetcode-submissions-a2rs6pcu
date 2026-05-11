class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& t : times) {
            auto u = t[0], v = t[1], wt = t[2];
            adj[u].push_back({v, wt});
        }

        set<int> vis;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k});
        int res = 0;
        while (not pq.empty()) {
            auto [wt, u] = pq.top();
            pq.pop();
            if (vis.contains(u)) {
                continue;
            }

            res = wt;
            vis.insert(u);
            for (auto [v, wt2] : adj[u]) {
                pq.push({wt + wt2, v});
            }
        }

        return vis.size() == n ? res : -1;
    }
};
