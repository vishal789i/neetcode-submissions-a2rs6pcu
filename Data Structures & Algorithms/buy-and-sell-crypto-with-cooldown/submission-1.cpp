class Solution {
public:
    int maxProfit(vector<int>& prices) {
        map<pair<int, int>, int> dp;
        function<int(int, bool)> dfs = [&] (int i, bool bought) {
            if (i >= prices.size()) {
                return 0;
            }

            if (dp.contains({i, bought})) {
                return dp[{i, bought}];
            }

            auto profitIfDayIsSkipped = dfs(i + 1, bought);
            if (bought) {
                return dp[{i, bought}] = max(profitIfDayIsSkipped, dfs(i + 2, false) + prices[i]);
            }

            return dp[{i, bought}] = max(profitIfDayIsSkipped, dfs(i + 1, true) - prices[i]);
        };

        return dfs(0, false);
    }
};
