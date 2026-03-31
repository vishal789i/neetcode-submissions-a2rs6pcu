class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }

        vector<vector<int>> adj(n);
        for (auto e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        auto bfs = [&] (int u) {
            queue<tuple<int, int, int>> q;
            q.push({-1, u, 0});
            int res = 0;
            while (not q.empty()) {
                auto [parent, cur, h] = q.front();
                q.pop();
                res = max(res, h);
                for (auto v : adj[cur]) {
                    if (v == parent) {
                        continue;
                    }

                    q.push({cur, v, h + 1});
                }
            }

            return res;
        };

        int minH = n;
        vector<pair<int, int>> heights;
        for (int i = 0; i < n; ++i) {
            int curH = bfs(i);
            heights.push_back({curH, i});
            minH = min(minH, curH);
        }

        auto it = heights.begin();
        while (it != heights.end()) {
            if (it->first != minH) {
                it = heights.erase(it);
            } else {
                it++;
            }
        }

        vector<int> res;
        for (int i = 0; i < heights.size(); ++i) {
            res.push_back(heights[i].second);
        }

        return res;
    }
};