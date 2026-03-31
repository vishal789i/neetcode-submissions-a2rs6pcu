class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1), size(n + 1, 1);
        for (int i = 1; i < n; ++i) {
            parent[i] = i;
        }
        
        auto unite = [&] (int u, int v) {
            auto find = [&] (int u) {
                while (u != parent[u]) {
                    u = parent[u];
                    parent[u] = parent[parent[u]];
                }

                return u;
            };

            auto pu = find(u), pv = find(v);
            if (pu == pv) {
                return false;
            }

            if (size[pu] > size[pv]) {
                parent[pv] = pu;
                size[pu] += size[pv];
            } else {
                parent[pu] = pv;
                size[pv] += size[pu];
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
