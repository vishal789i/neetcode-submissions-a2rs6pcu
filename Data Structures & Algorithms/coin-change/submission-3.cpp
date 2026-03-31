class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 1e9);
        dp[0] = 0;
        for (int curAmt = 1; curAmt <= amount; ++curAmt) {
            for (auto c : coins) {
                if (c <= curAmt) {
                    dp[curAmt] = min(dp[curAmt], 1 + dp[curAmt - c]);
                }
            }
        }

        return dp[amount] == 1e9 ? -1 : dp[amount];
    }
};
