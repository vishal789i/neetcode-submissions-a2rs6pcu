class Solution {
public:
    int minDistance(string word1, string word2) {
        map<pair<int, int>, int> dp;
        function<int(int, int)> dfs = [&] (int i, int j) {
            if (i == word1.size()) {
                return (int)word2.size() - j;
            }

            if (j == word2.size()) {
                return (int)word1.size() - i;
            }

            if (dp.contains({i, j})) {
                return dp[{i, j}];
            }

            if (word1[i] != word2[j]) {
                return dp[{i, j}] = 1 + min({dfs(i + 1, j + 1), dfs(i + 1, j), dfs(i, j + 1)});
            }

            return dp[{i, j}] = dfs(i + 1, j + 1);
        };

        return dfs(0, 0);
    }
};
