class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> indegrees(n);
        vector<vector<int>> adj(n);
        for (auto& p : prerequisites) {
            indegrees[p[1]]++;
            adj[p[0]].push_back(p[1]);
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegrees[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;
        while (not q.empty()) {
            auto cur = q.front();
            q.pop();
            topo.push_back(cur);
            for (auto nei : adj[cur]) {
                if (--indegrees[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        vector<bool> res;
        vector<vector<bool>> reachable(n, vector<bool>(n, false));
        for (auto u : topo) {
            for (auto v : adj[u]) {
                reachable[u][v] = true;
                for (auto k = 0; k < n; ++k) {
                    if (reachable[k][u]) {
                        reachable[k][v] = true;
                    }
                }
            }
        }

        for (auto& q : queries) {
            res.push_back(reachable[q[0]][q[1]]);
        }

        return res;
    }
};