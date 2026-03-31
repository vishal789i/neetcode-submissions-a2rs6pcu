class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> vertex2AdjVertices;

        vector<int> indegrees(numCourses);
        for (auto& pre : prerequisites) {
            vertex2AdjVertices[pre[0]].push_back(pre[1]);
            indegrees[pre[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < indegrees.size(); ++i) {
            if (indegrees[i] == 0) {
                q.push(i);
            }
        }

        int res = 0;
        while (not q.empty()) {
            auto vertex = q.front();
            q.pop();
            res++;

            for (auto adjV : vertex2AdjVertices[vertex]) {
                indegrees[adjV]--;
                if (indegrees[adjV] == 0) {
                    q.push(adjV);
                }
            }
        }

        return res == numCourses;
    }
};
