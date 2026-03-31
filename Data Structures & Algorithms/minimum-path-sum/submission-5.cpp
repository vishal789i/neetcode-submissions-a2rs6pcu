class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();  
        vector<vector<int>> dp(ROWS + 1, vector<int>(COLS + 1));

        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (r == 0 and c == 0) {
                    dp[r][c] = grid[r][c];
                } else {
                    int down = INT_MAX;
                    if (r > 0) {
                        down = dp[r - 1][c];
                    }

                    int right = INT_MAX;
                    if (c > 0) {
                        right = dp[r][c - 1];
                    }

                    dp[r][c] = grid[r][c] + min(down, right);
                }
            }
        }

        return dp[ROWS - 1][COLS - 1];
    }
};