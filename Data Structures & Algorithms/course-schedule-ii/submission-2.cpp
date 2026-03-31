class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> course2Preqs;
        for (auto preq: prerequisites) {
            course2Preqs[preq[0]].push_back(preq[1]);
        }

        set<int> vis;
        // set<int> resSet;
        vector<int> res;
        function<bool(int)> dfs = [&] (int course) {
            if (find(res.begin(), res.end(), course) != res.end()) {
                return true;
            }

            if (vis.count(course)) {
                return false;
            }

            vis.insert(course);

            for (auto preq: course2Preqs[course]) {
                if (not dfs(preq)) {
                    return false;
                }
            }

            vis.erase(course);
            // resSet.insert(course);
            res.push_back(course);
            return true;
        };

        for (int c = 0; c < numCourses; ++c) {
            if (not dfs(c)) {
                return {};
            }
        }

        return res;
    }
};
