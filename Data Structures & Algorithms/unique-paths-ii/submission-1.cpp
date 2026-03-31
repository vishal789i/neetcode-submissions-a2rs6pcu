class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        vector<vector<int>> dp(ROWS + 1, vector<int>(COLS + 1, -1));
        function<int(int, int)> dfs = [&] (int r, int c) {
            if (r < 0 or r >= ROWS or c < 0 or c >= COLS or grid[r][c] == 1) {
                return 0;
            }

            if (r == ROWS - 1 and c == COLS - 1) {
                return 1;
            }

            if (dp[r][c] != -1) {
                return dp[r][c];
            }

            return dp[r][c] = dfs(r + 1, c) + dfs(r, c + 1);
        };

        return dfs(0, 0);
    }
};