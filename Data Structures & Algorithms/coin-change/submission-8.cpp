class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int, int> dp;
        function<int(int)> dfs = [&] (int amount) {
            if (amount <= 0) {
                return 0;
            }

            if (dp.contains(amount)) {
                return dp[amount];
            }

            int res = 1e9;
            for (auto c : coins) {
                if (c <= amount) {
                    res = min(res, 1 + dfs(amount - c));
                }
            }

            return dp[amount] = res;
        };

        int res = dfs(amount);
        return res == 1e9 ? -1 : res;
    }
};
