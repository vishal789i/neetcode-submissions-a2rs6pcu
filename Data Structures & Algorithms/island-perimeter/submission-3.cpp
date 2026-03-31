class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        vector vis(ROWS, vector(COLS, -1));
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        function<int(int, int)> f = [&] (int r, int c) {
            vis[r][c] = 1;
            int res = 0;
            for (auto [dr, dc] : dirs) {
                auto newR = r + dr, newC = c + dc;
                if (newR < 0 or newR == ROWS or newC < 0 or newC == COLS or grid[newR][newC] == 0) {
                    res++;
                    continue;
                }

                if (vis[newR][newC]) {
                    continue;
                }

                res += f(newR, newC);
            }

            return res;
        };

        int res = 0;
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (grid[r][c] == 1) {
                    res += f(r, c);
                }
            }
        }

        return res;
    }
};