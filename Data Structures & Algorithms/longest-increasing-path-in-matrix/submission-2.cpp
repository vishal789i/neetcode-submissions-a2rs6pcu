class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& mat) {
        const auto ROWS = mat.size(), COLS = mat[0].size();
        vector<vector<int>> dp(ROWS, vector<int>(COLS, -1));
        function<int(int, int)> dfs = [&] (int r, int c) {
            if (dp[r][c] != -1) {
                return dp[r][c];
            }

            vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            int res = 1;
            for (auto [dr, dc] : dirs) {
                auto newR = r + dr, newC = c + dc;
                if (newR < 0 or newR >= ROWS or newC < 0 or newC >= COLS or mat[newR][newC] <= mat[r][c]) {
                    continue;
                }

                res = max(res, 1 + dfs(newR, newC));
            }
            return dp[r][c] = res;
        };

        int res = 1;
        for (auto r = 0; r < ROWS; ++r) {
            for (auto c = 0; c < COLS; ++c) {
                res = max(res, dfs(r, c));
            }
        }

        return res;
    }
};
