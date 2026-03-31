class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size(), COLS = heights[0].size();
        function<void(int, int, int, set<pair<int, int>>&)> dfs = [&] (int r, int c, int prevHeight, set<pair<int, int>>& vis) {
            if (r < 0 or r == ROWS or c < 0 or c == COLS or vis.contains({r, c}) or heights[r][c] < prevHeight) {
                return;
            }

            vis.insert({r, c});
            dfs(r + 1, c, heights[r][c], vis);
            dfs(r - 1, c, heights[r][c], vis);
            dfs(r, c + 1, heights[r][c], vis);
            dfs(r, c - 1, heights[r][c], vis);
        };

        set<pair<int, int>> pacificVisSet, atlanticVisSet;
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (r == 0 or c == 0) {
                    dfs(r, c, heights[r][c], pacificVisSet);
                }

                if (r == ROWS - 1 or c == COLS - 1) {
                    dfs(r, c, heights[r][c], atlanticVisSet);
                }
            }
        }

        vector<vector<int>> res;
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (pacificVisSet.contains({r, c}) and atlanticVisSet.contains({r, c})) {
                    res.push_back({r, c});
                }
            }
        }

        return res;
    }
};