class Solution {
public:
    int longestPalindromeSubseq(string s) {
        map<pair<int, int>, int> dp;
        function<int(int, int)> dfs = [&] (int i, int j) {
            if (i > j) {
                return 0;
            }

            if (i == j) {
                return 1;
            }

            if (dp.contains({i, j})) {
                return dp[{i, j}];
            }

            if (s[i] == s[j]) {
                return dp[{i, j}] = 2 + dfs(i + 1, j - 1);
            }

            return dp[{i, j}] = max(dfs(i + 1, j), dfs(i, j - 1));
        };

        return dfs(0, s.size() - 1);
    }
};