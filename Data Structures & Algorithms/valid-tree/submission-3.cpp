class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        map<int, vector<int>> vertex2AdjVerticesMap;

        for (auto edge: edges) {
            vertex2AdjVerticesMap[edge[0]].push_back(edge[1]);
            vertex2AdjVerticesMap[edge[1]].push_back(edge[0]);
        }

        set<int> vis;
        function<bool(int, int)> dfs = [&] (int currVertex, int parentVertex) {
            if (vis.count(currVertex)) {
                return false;
            }

            vis.insert(currVertex);

            for (auto adjVertex: vertex2AdjVerticesMap[currVertex]) {
                if (adjVertex == parentVertex) {
                    continue;
                }

                if (not dfs(adjVertex, currVertex)) {
                    return false;
                }
            }

            return true;
        };

        if (not dfs(0, -1)) {
            return false;
        }

        return vis.size() == n;
    }
};
