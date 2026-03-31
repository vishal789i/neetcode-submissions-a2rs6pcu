class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }

        vector<vector<int>> adj(n);
        vector<int> indegrees(n);
        for (auto e : edges) {
            int u = e[0], v = e[1];
            indegrees[u]++;
            indegrees[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int> q;
        for (int i = 0; i < indegrees.size(); ++i) {
            if (indegrees[i] == 1) {
                q.push(i);
            }
        }

        while (n > 2) {
            int size = q.size();
            n -= size;
            while (size--) {
                auto u = q.front();
                q.pop();
                for (auto v : adj[u]) {
                    if (--indegrees[v] == 1) {
                        q.push(v);
                    }
                }
            }
        }

        // <= 2 nodes remaining
        vector<int> res;
        while (not q.empty()) {
            res.push_back(q.front());
            q.pop();
        }

        return res;
    }
};