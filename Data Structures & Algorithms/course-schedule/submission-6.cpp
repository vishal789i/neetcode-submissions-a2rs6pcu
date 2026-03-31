class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, set<int>> adj;
        for (auto& p : prerequisites) {
            adj[p[0]].insert(p[1]);
        }

        set<int> vis;
        function<bool(int)> dfs = [&] (int cur) {
            if (adj[cur].empty()) {
                return true;
            }

            if (vis.contains(cur)) {
                return false;
            }

            vis.insert(cur);
            for (auto nei : adj[cur]) {
                if (not dfs(nei)) {
                    return false;
                }
            }

            vis.erase(cur);
            adj[cur].clear();
            return true;
        };

        for (int i = 0; i < numCourses; ++i) {
            if (not dfs(i)) {
                return false;
            }
        }

        return true;
    }
};
