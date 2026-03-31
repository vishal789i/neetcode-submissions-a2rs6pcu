class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        for (int t = 0; t <= amount; ++t) {
            if (t % coins[0] == 0) {
                dp[0][t] = t / coins[0];
            } else {
                dp[0][t] = 1e9;
            }
        }

        for (int i = 1; i < coins.size(); ++i) {
            for (int t = 0; t <= amount; ++t) {
                int notTake = dp[i - 1][t];
                int take = 1e9;
                if (coins[i] <= t) {
                    take = 1 + dp[i][t - coins[i]];
                }

                dp[i][t] = min(notTake, take);
            }
        }

        int res = dp[coins.size() - 1][amount];
        return res == 1e9 ? -1 : res;
    }
};
