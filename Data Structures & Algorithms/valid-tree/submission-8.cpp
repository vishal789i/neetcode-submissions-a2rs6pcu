class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        set<int> vis;
        function<bool(int, int)> dfs = [&] (int prev, int node) {
            if (vis.contains(node)) {
                return false;
            }

            vis.insert(node);
            for (auto nei : adj[node]) {
                if (prev == nei) {
                    continue;
                }

                if (not dfs(node, nei)) {
                    return false;
                }
            }

            return true;
        };

        return dfs(-1, 0) and vis.size() == n;
    }
};
