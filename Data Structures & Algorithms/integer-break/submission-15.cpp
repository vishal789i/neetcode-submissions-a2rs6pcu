class Solution {
public:
    int integerBreak(int n) {
        vector dp(n + 1, 0);
        dp[1] = 1;
        for (int j = 2; j <= n; ++j) {
            int res = 1 * (j - 1);
            for (int i = 1; i < j; ++i) {
                int prod = i * max(j - i, dp[j - i]);
                res = max(res, prod);
            }

            dp[j] = res;
        }

        return dp[n];
    }
};