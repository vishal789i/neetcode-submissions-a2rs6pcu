class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
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

        int res = 0;
        while (not q.empty()) {
            auto cur = q.front();
            q.pop();
            res++;
            for (auto nei : adj[cur]) {
                indegrees[nei]--;
                if (indegrees[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        return res == n;
    }
};
