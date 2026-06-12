class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector dp(s1.size() + 1, vector(s2.size() + 1, vector(s3.size() + 1, -1)));
        function<int(int, int, int)> dfs = [&] (int i, int j, int k) {
            if (i == s1.size() and j == s2.size() and k == s3.size()) {
                return 1;
            }

            if (dp[i][j][k] != -1) {
                return dp[i][j][k];
            }

            bool res = false;
            if (i < s1.size() and s1[i] == s3[k]) {
                res |= dfs(i + 1, j, k + 1);
            }
            
            if (j < s2.size() and s2[j] == s3[k]) {
                res |= dfs(i, j + 1, k + 1);
            }

            dp[i][j][k] = res;
            return dp[i][j][k];
        };

        return dfs(0, 0, 0);
    }
};
