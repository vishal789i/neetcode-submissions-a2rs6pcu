class Solution {
public:
    int uniquePaths(int rows, int cols) {
        map<pair<int, int>, int> dp;
        function<int(int, int)> dfs = [&] (int r, int c) {
            if (r < 0 or r >= rows or c < 0 or c >= cols) {
                return 0;
            }

            if (r == rows - 1 and c == cols -1) {
                return 1;
            }

            if (dp.contains({r, c})) {
                dp[{r, c}];
            }

            return dp[{r, c}] = dfs(r + 1, c) + dfs(r, c + 1);
        };

        return dfs(0, 0);
    }
};
