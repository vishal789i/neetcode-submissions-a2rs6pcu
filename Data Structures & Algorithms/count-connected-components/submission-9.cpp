class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n), rank(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        auto unionByRank = [&] (int u, int v) {
            auto findParent = [&] (int node) {
                while (node != parent[node]) {
                    parent[node] = parent[parent[node]];
                    node = parent[node];
                }

                return node;
            };

            auto pu = findParent(u);
            auto pv = findParent(v);
            if (pu == pv) {
                return false;
            }

            if (rank[pu] > rank[pv]) {
                parent[pv] = pu;
            } else if (rank[pu] < rank[pv]) {
                parent[pu] = pv;
            } else {
                parent[pu] = pv;
                rank[pv]++;
            }

            return true;
        };

        auto res = n;
        for (auto edge : edges) {
            if (unionByRank(edge[0], edge[1])) {
                res--;
            }
        }

        return res;
    }
};
