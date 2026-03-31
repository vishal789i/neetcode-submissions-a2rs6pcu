class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;
        for (int i = 0; i < equations.size(); ++i) {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];
            adj[u].push_back({v, val});
            adj[v].push_back({u, 1.0/val});
        }

        vector<double> res;
        for (auto q : queries) {
            string src = q[0];
            string dest = q[1];
            double ans = -1.0;
            if (adj.contains(src)) {
                unordered_set<string> vis;
                function<void(string, double)> dfs = [&] (string u, double prod) {
                    if (vis.contains(u)) {
                        return;
                    }

                    vis.insert(u);
                    if (u == dest) {
                        ans = prod;
                        return;
                    }

                    for (auto& [v, val] : adj[u]) {
                        dfs(v, prod * val);
                    }
                };

                dfs(src, 1.0);
            }

            res.push_back(ans);
        }

        return res;
    }
};