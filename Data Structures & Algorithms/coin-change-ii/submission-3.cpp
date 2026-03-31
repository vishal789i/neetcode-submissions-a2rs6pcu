class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int N = coins.size();
        vector<vector<int>> dp(amount + 1, vector<int>(coins.size(), -1));
        function<int(int, int)> dfs = [&] (int i, int curAmt) {
            if (curAmt == 0) {
                return 1;
            }

            if (i >= N or curAmt < 0) {
                return 0;
            }

            if (dp[curAmt][i] != -1) {
                return dp[curAmt][i];
            }

            return dp[curAmt][i] = dfs(i + 1, curAmt) + dfs(i, curAmt - coins[i]);
        };

        return dfs(0, amount);
    }
};
