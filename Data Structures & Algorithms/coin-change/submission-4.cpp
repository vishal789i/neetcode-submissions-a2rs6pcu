class Solution {
    map<pair<int, int>, int> dp;
public:
    int dfs(vector<int>& coins, int amount, int i) {
        if (i == coins.size()) {
            if (amount == 0) {
                return 0;
            }

            return 1e9;
        }

        if (dp[{amount, i}]) {
            return dp[{amount, i}];
        }

        int notPick = dfs(coins, amount, i + 1);
        int pick = 1e9;
        if (coins[i] <= amount) {
            pick = 1 + dfs(coins, amount - coins[i], i);
        }

        return dp[{amount, i}] = min(pick, notPick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int res = dfs(coins, amount, 0);
        return res == 1e9 ? -1 : res;
    }
};
