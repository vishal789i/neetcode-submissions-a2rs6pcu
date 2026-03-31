class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        map<int, vector<int>> vertex2AdjVerticesMap;

        function<bool(int, int, set<int>)> dfs = [&] (int currVertex, int parentVertex, set<int> vis) {
            if (vis.count(currVertex)) {
                return true;
            }

            vis.insert(currVertex);

            for (auto adjVertex: vertex2AdjVerticesMap[currVertex]) {
                if (adjVertex == parentVertex) {
                    continue;
                }

                if (dfs(adjVertex, currVertex, vis)) {
                    return true;
                }
            }

            return false;
        };

        for (auto edge: edges) {
            vertex2AdjVerticesMap[edge[0]].push_back(edge[1]);
            vertex2AdjVerticesMap[edge[1]].push_back(edge[0]);
            
            set<int> vis;
            if (dfs(edge[0], -1, vis)) {
                return edge;
            }
        }

        return {-1, -1};
    }
};
