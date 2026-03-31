class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegrees(numCourses);
        for (auto p : prerequisites) {
            adj[p[0]].push_back(p[1]);
            indegrees[p[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < indegrees.size(); ++i) {
            if (indegrees[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> res;
        while (not q.empty()) {
            auto v = q.front();
            q.pop();
            res.push_back(v);

            for (auto adjV : adj[v]) {
                if (--indegrees[adjV] == 0) {
                    q.push(adjV);
                }
            }
        }

        reverse(res.begin(), res.end());
        return res.size() == numCourses ? res : vector<int>();
    }
};
