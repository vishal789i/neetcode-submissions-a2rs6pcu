class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        
        vector<int> size(n, 1);
        auto unionBySize = [&] (int u, int v) {
            auto find = [&] (int node) {
                auto cur = node;
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

            if (size[pu] > size[pv]) {
                parent[pv] = pu;
                size[pu] += size[pv];
            } else {
                parent[pu] = pv;
                size[pv] += size[pu];
            }

            return true;
        };

        int res = n;
        for (auto& edge : edges) {
            if (unionBySize(edge[0], edge[1])) {
                res--;
            }
        }
        return res;
    }
};
