class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        vector dp(ROWS + 1, vector(COLS + 1, vector(ROWS + 1, -1)));
        function<int(int, int, int)> dfs = [&] (int r1, int c1, int r2) {
            int c2 = r1 + c1 - r2;
            if (r1 >= ROWS or r2 >= ROWS or c1 >= COLS or c2 >= COLS or grid[r1][c1] == -1 or grid[r2][c2] == -1) {
                return (int)-1e9;
            }

            if (r1 == ROWS - 1 and c1 == COLS - 1) {
                return grid[r1][c1];
            }

            if (dp[r1][c1][r2] != -1) {
                return dp[r1][c1][r2];
            }

            int res = grid[r1][c1];
            if (r1 != r2 or c1 != c2) {
                res += grid[r2][c2];
            }

            res += max({dfs(r1 + 1, c1, r2 + 1),   // down, down
                        dfs(r1, c1 + 1, r2),       // right, right
                        dfs(r1 + 1, c1, r2),       // down, right
                        dfs(r1, c1 + 1, r2 + 1)}); // right, down
            return dp[r1][c1][r2] = res;
        };

        return max(0, dfs(0, 0, 0));
    }
};