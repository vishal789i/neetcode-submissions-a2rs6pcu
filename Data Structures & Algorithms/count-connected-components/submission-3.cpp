class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        map<int, vector<int>> vertex2AdjVerticesMap;
        for (auto edge: edges) {
            vertex2AdjVerticesMap[edge[0]].push_back(edge[1]);
            vertex2AdjVerticesMap[edge[1]].push_back(edge[0]);
        }

        set<int> vis;
        function<void(int)> bfs = [&] (int vertex) {
            queue<int> q;
            q.push(vertex);

            while (not q.empty()) {
                auto currVertex = q.front();
                q.pop();

                if (vis.count(currVertex)) {
                    continue;
                }

                vis.insert(currVertex);

                for (auto adjVertex: vertex2AdjVerticesMap[currVertex]) {
                    q.push(adjVertex);
                }
            }
        };

        int res = 0;
        for (int v = 0; v < n; ++v) {
            if (not vis.count(v)) {
                bfs(v);
                res++;
            }
        }

        return res;
    }
};
