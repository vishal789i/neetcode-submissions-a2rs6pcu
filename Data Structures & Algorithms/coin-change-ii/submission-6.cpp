class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector dp(coins.size(), vector(amount + 1, -1));
        function<int(int, int)> f = [&] (int i, int amt) {
            if (i == 0) {
                return amt % coins[0] == 0 ? 1 : 0;
            }

            if (dp[i][amt] != -1) {
                return dp[i][amt];
            }

            auto notTake = f(i - 1, amt);
            auto take = 0;
            if (coins[i] <= amt) {
                take = f(i, amt - coins[i]);
            }

            return dp[i][amt] = take + notTake;
        };

        for (int amt = 0; amt <= amount; ++amt) {
            dp[0][amt] = amt % coins[0] == 0 ? 1 : 0;
        }

        for (int i = 1; i < coins.size(); ++i) {
            for (int amt = 0; amt <= amount; ++amt) {
                auto notTake = dp[i - 1][amt];
                auto take = 0;
                if (coins[i] <= amt) {
                    take = dp[i][amt - coins[i]];
                }

                dp[i][amt] = take + notTake;
            }
        }

        return dp[coins.size() - 1][amount];
    }
};
