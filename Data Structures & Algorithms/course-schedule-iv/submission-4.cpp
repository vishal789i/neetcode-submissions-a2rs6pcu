class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> indegrees(n);
        vector<set<int>> adj(n), preq(n);
        for (auto& p : prerequisites) {
            indegrees[p[1]]++;
            adj[p[0]].insert(p[1]);
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
                preq[nei].insert(cur);
                preq[nei].insert(preq[cur].begin(), preq[cur].end());
                if (--indegrees[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        vector<bool> res;
        for (auto q : queries) {
            res.push_back(preq[q[1]].contains(q[0]));
        }

        return res;
    }
};