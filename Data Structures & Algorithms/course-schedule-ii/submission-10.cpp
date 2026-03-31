class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> indegrees(n);
        vector<vector<int>> adj(n);
        for (auto& p : prerequisites) {
            indegrees[p[1]]++;
            adj[p[0]].push_back(p[1]);
        }


        queue<int> q;
        for (int i = 0; i < indegrees.size(); ++i) {
            if (indegrees[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> res;
        while (not q.empty()) {
            auto cur = q.front();
            q.pop();
            res.push_back(cur);
            for (auto nei : adj[cur]) {
                indegrees[nei]--;
                if (indegrees[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        reverse(res.begin(), res.end());
        return res.size() == n ? res : vector<int>();
    }
};
