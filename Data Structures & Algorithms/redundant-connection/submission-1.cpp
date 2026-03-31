class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1), size(n + 1, 1);
        for (int i = 0; i <= n; ++i) {
            parent[i] = i;
        }

        auto unionBySize = [&] (int u, int v) {
            auto find = [&] (int node) {
                while (node != parent[node]) {
                    parent[node] = parent[parent[node]];
                    node = parent[node];
                }

                return node;
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
            if (not unionBySize(e[0], e[1])) {
                return e;
            }
        }

        return {};
    }
};
