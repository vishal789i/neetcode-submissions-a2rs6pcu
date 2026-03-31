class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }

        set<int> vis;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k});
        int res = 0;
        while (not pq.empty()) {
            auto [w1, n1] = pq.top();
            pq.pop();
            if (vis.contains(n1)) {
                continue;
            }
            
            res = w1; // min time/wt till now
            vis.insert(n1);
            for (auto& [n2, w2] : adj[n1]) {
                pq.push({w1 + w2, n2});
            }
        }

        return vis.size() == n ? res : -1;
    }
};
