class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n);
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        function<void(int)> dfs = [&] (int node) {
            for (auto nei : adj[node]) {
                if (not vis[nei]) {
                    vis[nei] = true;
                    dfs(nei);
                }
            }
        };

        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (not vis[i]) {
                dfs(i);
                res++;
            }
        }

        return res;
    }
};
