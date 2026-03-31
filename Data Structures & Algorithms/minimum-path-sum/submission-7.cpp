class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        vector<int> prev(COLS + 1, 0);
        for (int r = 0; r < ROWS; ++r) {
            vector<int> cur(COLS + 1, 0);
            for (int c = 0; c < COLS; ++c) {
                if (r == 0 and c == 0) {
                    cur[c] = grid[r][c];
                } else {
                    int up = INT_MAX;
                    if (r > 0) {
                        up = prev[c];
                    }

                    int left = INT_MAX;
                    if (c > 0) {
                        left = cur[c - 1];
                    }

                    cur[c] = grid[r][c] + min(up, left);
                }
            }

            prev = cur;
        }

        return prev[COLS - 1];
    }
};