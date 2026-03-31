class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> parent(n), size(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        auto unite = [&] (int u, int v) {
            auto find = [&] (int u) {
                while (u != parent[u]) {
                    parent[u] = parent[parent[u]];
                    u = parent[u];
                }

                return u;
            };

            auto pu = find(u), pv = find(v);
            if (pu == pv) {
                return false;
            }

            if (size[pv] >= size[pu]) {
                parent[pu] = pv;
                size[pv] += size[pu];
            } else {
                parent[pv] = pu;
                size[pu] += size[pv];
            }

            return true;
        };

        for (auto& e : edges) {
            if (not unite(e[0], e[1])) {
                return e;
            }
        }

        return {};
    }
};
