class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        auto ROWS = grid.size(), COLS = grid[0].size();
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        function<int(int, int)> dfs = [&] (int r, int c) {
            if (r < 0 or r >= ROWS or c < 0 or c >= COLS or grid[r][c] == 0) {
                return 1;
            }

            if (grid[r][c] == -1) {
                return 0;
            }

            grid[r][c] = -1;

            int res = 0;
            for (auto dir : dirs) {
                auto newR = r + dir.first, newC = c + dir.second;
                res += dfs(newR, newC);
            }
            return res;
        };

        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (grid[r][c] == 1) {
                    return dfs(r, c);
                }
            }
        }

        return 0;
    }
};