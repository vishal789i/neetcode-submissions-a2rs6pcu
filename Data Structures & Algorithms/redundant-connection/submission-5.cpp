/*
       0 1 2 3 4 5
parent 0 1 1 1 1 5
size   1 4 1 1 1 1


*/
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = 100;
        vector<int> parent(n), size(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        auto unite = [&] (int u, int v) {
            auto find = [&] (int u) {
                while (u != parent[u]) {
                    u = parent[u];
                    parent[parent[u]] = parent[u];
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
