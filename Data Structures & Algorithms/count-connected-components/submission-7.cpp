class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n), size(n, 1);
        for (int i = 0; i < n; ++i) {
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

            auto parentU = find(u);
            auto parentV = find(v);
            if (parentU == parentV) {
                return false;
            }

            if (size[parentU] > size[parentV]) {
                parent[parentV] = parentU;
                size[parentU] += size[parentV];
            } else {
                parent[parentU] = parentV;
                size[parentV] += size[parentU];
            }

            return true;
        };

        int res = n;
        for (auto edge : edges) {
            if (unionBySize(edge[0], edge[1])) {
                res--;
            }
        }

        return res;
    }
};
