class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        function<int(int, int)> dfs = [&] (int i, int j) {
            if (i == word1.size()) {
                return (int)word2.size() - j;
            }

            if (j == word2.size()) {
                return (int)word1.size() - i;
            }

            if (dp[i][j] != -1) {
                return dp[i][j];
            }

            int res = 0;
            if (word1[i] == word2[j]) {
                res = dfs(i + 1, j + 1);
            } else {
                res = 1 + min({dfs(i + 1, j + 1), dfs(i + 1, j), dfs(i, j + 1)}); // replace, delete, insert
            }
            return dp[i][j] = res;
        };

        return dfs(0, 0);
    }
};
