class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& mat) {
        const auto ROWS = mat.size(), COLS = mat[0].size();
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>> dp(ROWS + 1, vector<int>(COLS + 1, -1));
        function<int(int, int)> dfs = [&] (int r, int c) {
            if (dp[r][c] != -1) {
                return dp[r][c];
            }

            int res = 1;
            for (auto it : dirs) {
                auto newR = r + it.first, newC = c + it.second;
                if (newR >= 0 and newR < ROWS and newC >= 0 and newC < COLS and mat[newR][newC] > mat[r][c]) {
                    res = max(res, 1 + dfs(newR, newC));
                }
            }

            return dp[r][c] = res;
        };

        int res = 0;
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                res = max(res, dfs(i, j));
            }
        }

        return res;
    }
};
