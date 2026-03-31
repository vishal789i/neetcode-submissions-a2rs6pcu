class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> dp(k + maxPts, -1);
        function<double(int)> dfs = [&] (int curPts) {
            if (curPts >= k) { // stop drawing
                return curPts <= n ? 1.0 : 0.0;
            }

            if (dp[curPts] != -1.0) {
                return dp[curPts];
            }

            double prob = 0.0;
            for (int i = 1; i <= maxPts; ++i) {
                prob += dfs(curPts + i);
            }

            return dp[curPts] = prob / maxPts;
        };

        return dfs(0);
    }
};