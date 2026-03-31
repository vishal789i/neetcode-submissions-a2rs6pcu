class Solution {
public:
    map<int, int> dp;
    int integerBreak(int n) {
        if (n == 1) {
            return 1;
        }

        if (dp[n]) {
            return dp[n];
        }

        int res = 1 * (n - 1);
        for (int i = 1; i < n; ++i) {
            int prod = i * max(n - i, integerBreak(n - i));
            res = max(res, prod);
        }

        return dp[n] = res;
    }
};