class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        function<int(int, int)> dfs = [&] (int i, int amt) {
            if (i == 0) {
                if (amt % coins[0] == 0) {
                    return amt / coins[0];
                } else {
                    return (int)1e9;
                }
            }

            if (dp[i][amt] != -1) {
                return dp[i][amt];
            }

            int notTake = dfs(i - 1, amt);
            int take = 1e9;
            if (coins[i] <= amt) {
                take = 1 + dfs(i, amt - coins[i]);
            }

            return dp[i][amt] = min(notTake, take);
        };

        int res = dfs(coins.size() - 1, amount);
        return res == 1e9 ? -1 : res;
    }
};
