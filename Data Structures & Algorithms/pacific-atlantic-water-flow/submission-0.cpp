class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int R = heights.size(), C = heights[0].size();
        set<pair<int, int>> pacificVisSet;
        set<pair<int, int>> atlanticVisSet;

        function<void(int, int, set<pair<int, int>>&, int)> dfs = [&] (int r, int c, set<pair<int, int>>& visSet, int prevHeight) {
            if (r < 0 or r == R or c < 0 or c == C or visSet.count({r, c}) or heights[r][c] < prevHeight) {
                return;
            }

            visSet.insert({r, c});
            vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            for (auto dir: dirs) {
                auto dr = r + dir.first, dc = c + dir.second;
                dfs(dr, dc, visSet, heights[r][c]);
            }
        };

        for (int r = 0; r < R; ++r) {
            dfs(r, 0, pacificVisSet, heights[r][0]);
            dfs(r, C - 1, atlanticVisSet, heights[r][C - 1]);
        }

        for (int c = 0; c < C; ++c) {
            dfs(0, c, pacificVisSet, heights[0][c]);
            dfs(R - 1, c, atlanticVisSet, heights[R - 1][c]);
        }
        
        vector<vector<int>> res;
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (pacificVisSet.count({r, c}) and atlanticVisSet.count({r, c})) {
                    res.push_back({r, c});
                }
            }
        }

        return res;
    }
};
