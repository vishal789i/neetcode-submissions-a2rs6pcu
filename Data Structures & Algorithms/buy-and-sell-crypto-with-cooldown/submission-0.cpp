class Solution {
public:
    enum enSide {
        BUY = 0,
        SELL = 1
    };

    int maxProfit(vector<int>& prices) {
        map<pair<int, int>, int> memo;

        function<int(int, enSide)> dfs = [&] (int i, enSide side) {
            if (i >= prices.size()) return 0;
            if (memo.count({i, side})) return memo[{i, side}];

            int coolDownProfit = dfs(i + 1, side);
            
            auto nextSide = side == BUY ? SELL : BUY;
            if (side == BUY) {
                int buyProfit = dfs(i + 1, nextSide) - prices[i];
                memo[{i, side}] = max(coolDownProfit, buyProfit);
            } else {
                int sellProfit = dfs(i + 2, nextSide) + prices[i];
                memo[{i, side}] = max(coolDownProfit, sellProfit);
            }

            return memo[{i, side}];
        };

        return dfs(0, BUY);
    }
};
