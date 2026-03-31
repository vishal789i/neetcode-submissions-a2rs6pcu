class Solution {
public:
    vector<int> dp;
    Solution() {
        dp.assign(10001, -1);
    }
    int numSquares(int n) {
        if (n <= 0) {
            return 0;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        int res = INT_MAX;
        for (int i = 1; i <= sqrt(n); ++i) {
            res = min(res, 1 + numSquares(n - pow(i, 2)));
        }
        return dp[n] = res;
    }
};