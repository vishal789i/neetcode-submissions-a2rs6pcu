class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n), rank(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        auto unionByRank = [&] (int u, int v) {
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

            if (rank[parentU] > rank[parentV]) {
                parent[parentV] = parentU;
            } else if (rank[parentU] < rank[parentV]) {
                parent[parentU] = parentV;
            } else {
                parent[parentU] = parentV;
                rank[parentV]++;
            }

            return true;
        };

        int res = n;
        for (auto edge : edges) {
            if (unionByRank(edge[0], edge[1])) {
                res--;
            }
        }

        return res;
    }
};
