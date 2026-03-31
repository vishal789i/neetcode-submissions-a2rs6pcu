class Solution {
public:
    unordered_map<int, int> amount2MinCoins;
    int dfs(vector<int>& coins, int amount) {
        if (amount == 0) return 0;

        if (amount2MinCoins.count(amount)) {
            return amount2MinCoins[amount];
        }

        int res = 1e9;
        for (auto coin : coins) {
            if (amount - coin >= 0) {
                res = min(res, 1 + dfs(coins, amount - coin));
            }
        }

        return amount2MinCoins[amount] = res;
    }

    int coinChange(vector<int>& coins, int amount) {
        int minCoins = dfs(coins, amount);
        return (minCoins >= 1e9) ? -1 : minCoins;
    }
};
