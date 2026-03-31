class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n);
        function<bool(int, int)> dfs = [&] (int node, int parent) {
            vis[node] = 1;
            for (auto nei : adj[node]) {
                if (not vis[nei]) {
                    if (not dfs(nei, node)) {
                        return false;
                    }
                } else if (nei != parent) {
                    return false;
                }
            }

            return true;
        };

        if (not dfs(0, -1)) {
            return false;
        }

        for (auto v : vis) {
            if (not v) {
                return false;
            }
        }

        return true;
    }
};
