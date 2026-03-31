class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> dp(n + 1);
        dp[0] = 1.0;
        for (int curPts = 1; curPts <= n; ++curPts) {
            for (int draw = 1; draw <= maxPts; ++draw) {
                if (curPts - draw >= 0 and curPts - draw < k) {
                    dp[curPts] += dp[curPts - draw] / maxPts;
                }
            }
        }

        double res = 0.0;
        for (int i = k; i <= n; ++i) {
            res += dp[i];
        }

        return res;
    }
};