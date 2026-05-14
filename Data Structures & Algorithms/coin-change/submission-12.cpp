class Solution {
public:
    int dfs(vector<int>& coins, int amount, int i) {
        if (i >= coins.size()) {
            if (amount == 0) {
                return 0;
            }

            return 1e9;
        }

        int take = 1e9;
        if (coins[i] <= amount) {
            take = 1 + dfs(coins, amount - coins[i], i);
        }

        int notTake = dfs(coins, amount, i + 1);
        return min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int res = dfs(coins, amount, 0);
        return res == 1e9 ? -1 : res;
    }
};
