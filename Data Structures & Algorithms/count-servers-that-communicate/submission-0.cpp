class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        int res = 0;
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (grid[r][c] == 0) {
                    continue;
                }

                bool found = false;
                for (int c1 = 0; c1 < COLS; ++c1) {
                    if (c != c1 and grid[r][c1] == 1) {
                        found = true;
                    }
                }

                if (not found) {
                    for (int r1 = 0; r1 < ROWS; ++r1) {
                        if (r != r1 and grid[r1][c] == 1) {
                            found = true;
                        }
                    }
                }

                if (found) {
                    res++;
                }
            }
        }

        return res;
    }
};