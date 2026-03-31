class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int ROWS = points.size(), COLS = points[0].size();
        vector<vector<long long>> dp(ROWS, vector<long long>(COLS, -1));
        function<long long(int, int)> dfs = [&] (int r, int c) {
            if (r == ROWS - 1) {
                return points[r][c] * 1LL;
            }

            if (dp[r][c] != -1) {
                return dp[r][c];
            }

            for (int c1 = 0; c1 < COLS; ++c1) {
                dp[r][c] = max(dp[r][c], dfs(r + 1, c1) - abs(c1 - c) + points[r][c]);
            }

            return dp[r][c];
        };

        long long ans = 0;
        for (int c = 0; c < COLS; c++) {
            ans = max(ans, dfs(0, c));
        }

        return ans;
    }
};

//  3 + 