class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ROWS = matrix.size(), COLS = matrix[0].size();
        vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector dp(ROWS, vector(COLS, -1));
        function<int(int, int)> dfs = [&] (int r, int c) {
            if (dp[r][c] != -1) {
                return dp[r][c];
            }
            int res = 1;
            for (auto [dr, dc] : dirs) {
                auto newR = r + dr, newC = c + dc;
                if (newR < 0 or newR == ROWS or newC < 0 or newC == COLS or matrix[newR][newC] <= matrix[r][c]) {
                    continue;
                }

                res = max(res, 1 + dfs(newR, newC));
            }

            return dp[r][c] = res;
        };

        int res = 1;
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                res = max(res, dfs(r, c));
            }
        }

        return res;
    }
};
