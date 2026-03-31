class Solution {
    map<int, long long> dp;

public:
    int dfs(vector<int>& coins, int amount, long long curAmt) {
        if (curAmt == amount) {
            return 0;
        }

        if (dp.contains(curAmt)) {
            return dp[curAmt];
        }

        int res = 1e9;
        for (int j = 0; j < coins.size(); ++j) {
            if (curAmt + coins[j] <= amount) {
                res = min(res, 1 + dfs(coins, amount, curAmt + coins[j]));
            }
        }

        return dp[curAmt] = res;
    }

    int coinChange(vector<int>& coins, int amount) {
        auto res = dfs(coins, amount, 0);
        return res >= 1e9 ? -1 : res;
    }
};
