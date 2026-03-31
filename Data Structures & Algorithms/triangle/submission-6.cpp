class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        map<pair<int, int>, int> dp;
        function<int(int, int)> dfs = [&] (int r, int c) {
            if (r == triangle.size()) {
                return 0;
            }

            if (c == triangle[r].size()) {
                return INT_MAX;
            }

            if (dp.contains({r, c})) {
                return dp[{r, c}];
            }

            return dp[{r, c}] = triangle[r][c] + min(dfs(r + 1, c), dfs(r + 1, c + 1));
        };

        return dfs(0, 0);
    }
};