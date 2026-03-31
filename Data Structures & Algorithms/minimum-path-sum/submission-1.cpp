class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const auto ROWS = grid.size(), COLS = grid[0].size();
        vector<vector<int>> dp(ROWS + 1, vector<int>(COLS + 1, -1));
        function<int(int, int)> dfs = [&] (int r, int c) {
            if (r == ROWS - 1 and c == COLS - 1) {
                return grid[r][c];
            }

            if (r >= ROWS or c >= COLS) {
                return INT_MAX;
            }

            if (dp[r][c] != -1) {
                return dp[r][c];
            }
            
            return dp[r][c] = grid[r][c] + min(dfs(r + 1, c), dfs(r, c + 1));
        };

        return dfs(0, 0);
    }
};