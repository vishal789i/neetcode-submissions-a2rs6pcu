class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ROWS = matrix.size(), COLS = matrix[0].size();
        int res = 0;
        vector dp(ROWS + 1, vector(COLS + 1, 0));
        for (int r = ROWS - 1; r >= 0; --r) {
            for (int c = COLS - 1; c >= 0; --c) {
                if (matrix[r][c] == '0') {
                    dp[r][c] = 0;
                } else {
                    dp[r][c] = 1 + min({dp[r][c + 1], dp[r + 1][c + 1], dp[r + 1][c]});
                    res = max(res, dp[r][c]);
                }
            }
        }

        return res * res;
    }
};