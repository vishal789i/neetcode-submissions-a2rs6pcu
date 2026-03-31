class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        function<int(int, int)> dfs = [&] (int r, int c) {
            if (r == m - 1 and c == n - 1) {
                return 1;
            }

            if (r > m or c > n) {
                return 0;
            }

            if (dp[r][c] != -1) {
                return dp[r][c];
            }

            return dp[r][c] = dfs(r + 1, c) + dfs(r, c + 1);
        };

        return dfs(0, 0);
    }
};
