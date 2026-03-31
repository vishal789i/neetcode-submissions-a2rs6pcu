class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        const auto ROWS = grid.size(), COLS = grid[0].size();
        function<void(int, int)> dfs = [&] (int r, int c) {
            if (r < 0 or r >= ROWS or c < 0 or c >= COLS or grid[r][c] != '1') {
                return;
            }

            grid[r][c] = '*';
            dfs(r - 1, c);
            dfs(r + 1, c);
            dfs(r, c - 1);
            dfs(r, c + 1);
        };

        int res = 0;
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (grid[r][c] == '1') {
                    dfs(r, c);
                    res++;
                }
            }
        }

        return res;
    }
};
