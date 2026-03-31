class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        map<int, vector<int>> vertex2AdjVerticesMap;
        for (auto edge: edges) {
            vertex2AdjVerticesMap[edge[0]].push_back(edge[1]);
            vertex2AdjVerticesMap[edge[1]].push_back(edge[0]);
        }

        set<int> vis;
        function<void(int)> dfs = [&] (int vertex) {
            if (vis.count(vertex)) {
                return;
            }

            vis.insert(vertex);

            for (auto adjVertex: vertex2AdjVerticesMap[vertex]) {
                dfs(adjVertex);
            }
        };

        int res = 0;
        for (int v = 0; v < n; ++v) {
            if (not vis.count(v)) {
                dfs(v);
                res++;
            }
        }

        return res;
    }
};
