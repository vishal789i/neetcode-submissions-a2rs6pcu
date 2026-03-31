class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> course2PreqsVecMap;
        vector<int> course2IndegreeMap(numCourses, 0);

        for (auto preq: prerequisites) {
            course2IndegreeMap[preq[0]]++;
            course2PreqsVecMap[preq[1]].push_back(preq[0]);
        }

        vector<int> res;
        function<void(int)> topoDfs = [&] (int course) {
            res.push_back(course);
            course2IndegreeMap[course]--;

            for (auto preq: course2PreqsVecMap[course]) {
                course2IndegreeMap[preq]--;
                if (course2IndegreeMap[preq] == 0) {
                    topoDfs(preq);
                }
            }
        };

        for (int c = 0; c < numCourses; ++c) {
            if (course2IndegreeMap[c] == 0) {
                topoDfs(c);
            }
        }

        if (res.size() != numCourses) return {};
        return res;
    }
};
