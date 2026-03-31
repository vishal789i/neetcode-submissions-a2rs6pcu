class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        function<int(int, int)> dfs = [&] (int i, int j) {
            // dont change order
            if (j == t.size()) {
                return 1;
            }

            if (i == s.size()) {
                return 0;
            }

            if (dp[i][j] != -1) {
                return dp[i][j];
            }
            
            int res = 0;
            if (s[i] == t[j]) {
                res = dfs(i + 1, j + 1) + dfs(i + 1, j);
            } else {
                res = dfs(i + 1, j);
            }

            return dp[i][j] = res;
        };

        return dfs(0, 0);
    }
};
