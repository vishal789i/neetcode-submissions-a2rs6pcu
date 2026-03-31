class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        set<int> vis;
        function<bool(int, int)> dfs = [&] (int prev, int cur) {
            if (vis.count(cur)) return false;
            vis.insert(cur);
            for (auto v : adj[cur]) {
                if (v == prev) continue;
                if (not dfs(cur, v)) return false;
            }
            return true;
        };

        if (not dfs(-1, 0)) return false;

        return vis.size() == n;
    }
};
