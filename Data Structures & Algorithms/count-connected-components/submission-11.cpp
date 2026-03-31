class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n);
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        function<void(int)> bfs = [&] (int node) {
            queue<int> q;
            q.push(node);
            while (not q.empty()) {
                auto cur = q.front();
                q.pop();
                for (auto nei : adj[cur]) {
                    if (not vis[nei]) {
                        vis[nei] = true;
                        q.push(nei);
                    }
                }
            }
        };

        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (not vis[i]) {
                bfs(i);
                res++;
            }
        }

        return res;
    }
};
