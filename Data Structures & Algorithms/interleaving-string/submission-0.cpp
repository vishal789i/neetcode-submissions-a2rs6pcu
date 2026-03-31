class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;

        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));  
        function<bool(int, int, int)> dfs = [&] (int i, int j, int k) -> bool {
            if (k == s3.size()) {
                return (i == s1.size() and j == s2.size());
            }

            if (dp[i][j] != -1) {
                return dp[i][j];
            }

            bool res = false;
            if (i < s1.size() and s1[i] == s3[k]) {
                res = dfs(i + 1, j, k + 1);
            }
            
            if (not res and j < s2.size() and s2[j] == s3[k]) {
                res = dfs(i, j + 1, k + 1);
            }

            return dp[i][j] = res;
        };

        return dfs(0, 0, 0);
    }
};
