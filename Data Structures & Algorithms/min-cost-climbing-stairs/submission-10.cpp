class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        function<int(int)> f = [&] (int i) {
            if (i >= cost.size()) {
                return 0;
            }

            return cost[i] + min(f(i + 1), f(i + 2));
        };

        vector dp(cost.size() + 2, 0);
        dp[cost.size()] = 0;
        dp[cost.size() + 1] = 0;
        for (int i = cost.size() - 1; i >= 0; --i) {
            dp[i] = cost[i] + min(dp[i + 1], dp[i + 2]);
        }

        return min(dp[0], dp[1]);
    }
};
