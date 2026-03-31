class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        set<int> vis;
        vis.insert(0);
        stack<pair<int, int>> stk;
        stk.push({-1, 0});
        while (not stk.empty()) {
            auto [parent, cur] = stk.top();
            stk.pop();
            for (auto nei : adj[cur]) {
                if (nei == parent) {
                    continue;
                }

                if (vis.contains(nei)) {
                    return false;
                }

                vis.insert(nei);
                stk.push({cur, nei});
            }
        }

        return vis.size() == n;
    }
};
