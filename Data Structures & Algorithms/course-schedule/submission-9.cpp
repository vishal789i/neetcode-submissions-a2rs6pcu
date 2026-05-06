class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegrees(numCourses);
        for (auto& p : prerequisites) {
            adj[p[0]].push_back(p[1]);
            indegrees[p[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegrees[i] == 0) {
                q.push(i);
            }
        }

        while (not q.empty()) {
            auto cur = q.front();
            q.pop();
            numCourses--;
            for (auto nei : adj[cur]) {
                if (--indegrees[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        return numCourses == 0;
    }
};
