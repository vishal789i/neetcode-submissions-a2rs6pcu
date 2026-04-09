class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> parent(n), size(n, 1);
        for (auto i = 0; i < n; ++i) {
            parent[i] = i;
        }

        auto find = [&] (int u) {
            while (u != parent[u]) {
                u = parent[u];
                parent[u] = parent[parent[u]];
            }

            return u;
        };

        auto unite = [&] (int u, int v) {
            auto pu = find(u), pv = find(v);
            if (pu == pv) {
                return false;
            }

            if (size[pu] > size[pv]) {
                size[pu] += size[pv];
                parent[pv] = pu;
            } else {
                size[pv] += size[pu];
                parent[pu] = pv;
            }

            return true;
        };

        vector<tuple<int, int, int>> edges;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                auto cost = abs(points[i][0] - points[j][0])
                          + abs(points[i][1] - points[j][1]);
                edges.push_back({cost, i, j});
            }
        }

        sort(edges.begin(), edges.end());
        int res = 0;
        for (auto [w, u, v] : edges) {
            if (find(u) != find(v)) {
                res += w;
                unite(u, v);
            }
        }

        return res;
    }
};
