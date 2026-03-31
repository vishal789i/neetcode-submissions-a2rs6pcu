class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector dp(n + 1, vector(m + 1, -1));
        function<int(int, int)> dfs = [&] (int i, int j) {
            if (i == 0 or j == 0) {
                return 0;
            }

            if (dp[i][j] != -1) {
                return dp[i][j];
            }

            if (text1[i - 1] == text2[j - 1]) {
                return dp[i][j] = 1 + dfs(i - 1, j - 1);
            }

            return dp[i][j] = max(dfs(i - 1, j), dfs(i, j - 1));
        };

        return dfs(n, m);
    }
};
