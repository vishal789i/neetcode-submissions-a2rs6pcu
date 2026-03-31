class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();  
        map<pair<int, int>, int> dp;
        function<int(int, int)> dfs = [&] (int r, int c) {
            if (r < 0 or r >= ROWS or c < 0 or c >= COLS) {
                return INT_MAX;
            }

            if (r == ROWS - 1 and c == COLS - 1) {
                return grid[r][c];
            }

            if (dp.contains({r, c})) {
                return dp[{r, c}];
            }

            return dp[{r, c}] = grid[r][c] + min(dfs(r + 1, c), dfs(r, c + 1));
        };

        return dfs(0, 0);
    }
};