class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> parent(n), rank(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        auto unionByRank = [&] (int u, int v) {
            auto find = [&] (int cur) {
                while (cur != parent[cur]) {
                    parent[cur] = parent[parent[cur]];
                    cur = parent[cur];
                }

                return cur;
            };

            auto pu = find(u);
            auto pv = find(v);
            if (pu == pv) {
                return false;
            }

            if (rank[pu] > rank[pv]) {
                parent[pv] = pu;
                rank[pu]++;
            } else if (rank[pu] < rank[pv]) {
                parent[pu] = pv;
                rank[pv]++;
            } else {
                parent[pu] = pv;
                rank[pv]++;
            }

            return true;
        };

        int res = n;
        for (auto e : edges) {
            res--;
            if (not unionByRank(e[0], e[1])) {
                return false;
            }
        }

        return res == 1;
    }
};
