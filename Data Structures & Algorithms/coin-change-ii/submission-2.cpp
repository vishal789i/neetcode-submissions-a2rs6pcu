class Solution {
public:
    int change(int amount, vector<int>& coins) {        
        vector<vector<int>> dp(amount + 1, vector<int>(coins.size(), -1));
        function<int(int, int)> dfs = [&] (int idx, int curAmt) {
            if (curAmt == 0) {
                return 1;
            }

            if (curAmt < 0 or idx < 0) {
                return 0;
            }

            if (dp[curAmt][idx] != -1) {
                return dp[curAmt][idx];
            }

            int notTake = dfs(idx - 1, curAmt);
            int take = 0;
            if (coins[idx] <= curAmt) {
                take = dfs(idx, curAmt - coins[idx]);
            }
            return dp[curAmt][idx] = take + notTake;
        };

        return dfs(coins.size() - 1, amount);
    }
};
