class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ROWS = matrix.size(), COLS = matrix[0].size();
        int res = 0;
        vector cur(COLS + 1, 0), nxt(COLS + 1, 0);
        for (int r = ROWS - 1; r >= 0; --r) {
            for (int c = COLS - 1; c >= 0; --c) {
                if (matrix[r][c] == '0') {
                    cur[c] = 0;
                } else {
                    cur[c] = 1 + min({cur[c + 1], nxt[c + 1], nxt[c]});
                    res = max(res, cur[c]);
                }
            }

            nxt = cur;
        }

        return res * res;
    }
};