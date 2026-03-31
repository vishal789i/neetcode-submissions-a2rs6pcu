class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        map<int, vector<int>> vertex2AdjVerticesMap;
        set<int> vis;

        for (auto edge: edges) {
            vertex2AdjVerticesMap[edge[0]].push_back(edge[1]);
            vertex2AdjVerticesMap[edge[1]].push_back(edge[0]);
        }

        // bfs
        queue<pair<int, int>> q;
        q.push({0, -1});
        vis.insert(0);
        
        while (not q.empty()) {
            int currVertex = q.front().first, parentVertex = q.front().second;
            q.pop();
            
            for (auto adjVertex: vertex2AdjVerticesMap[currVertex]) {
                if (adjVertex == parentVertex) {
                    continue;
                }

                if (vis.count(adjVertex)) {
                    return false;
                }

                q.push({adjVertex, currVertex});
                vis.insert(adjVertex);
            }
        }

        return vis.size() == n;
    }
};
