class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        auto ROWS = triangle.size();
        vector dp(ROWS, vector(ROWS, -1));
        for (int r = ROWS - 1; r >= 0; --r) {
            for (int c = triangle[r].size() - 1; c >= 0; --c) {
                if (r == ROWS - 1) {
                    if (c < triangle[r].size()) {
                        dp[r][c] = triangle[r][c];
                    } else {
                        dp[r][c] = INT_MIN;
                    }
                } else {
                    dp[r][c] = triangle[r][c] + min(dp[r + 1][c], dp[r + 1][c + 1]);
                }
            }
        }

        return dp[0][0];
    }
};