class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> course2PrequisitesVecMap;
        for (auto& prerequisite: prerequisites) {
            course2PrequisitesVecMap[prerequisite[0]].push_back(prerequisite[1]);
        }

        unordered_set<int> vis;
        function<bool(int)> dfs = [&] (int course) {
            if (course2PrequisitesVecMap[course].empty()) {
                return true;
            }

            if (vis.count(course)) {
                return false;
            }
            
            vis.insert(course);

            for (auto prequisite: course2PrequisitesVecMap[course]) {
                if (not dfs(prequisite)) {
                    return false;
                }
            }

            course2PrequisitesVecMap[course].clear();
            vis.erase(course);
            return true;
        };

        for (int c = 0; c < numCourses; ++c) {
            if (not dfs(c)) {
                return false;
            }
        }

        return true;
    }
};
