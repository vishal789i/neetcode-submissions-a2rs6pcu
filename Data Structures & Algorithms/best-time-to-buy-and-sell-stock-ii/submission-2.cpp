class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        function<int(int, int)> f = [&] (int i, int canBuy) {
            if (i == n) {
                return 0;
            }
            
            int res = 0;
            if (canBuy) {
                res = max(-prices[i] + f(i + 1, 0), f(i + 1, 1));
            } else {
                res = max(prices[i] + f(i + 1, 1), f(i + 1, 0));
            }

            return res;
        };

        vector dp(n + 1, vector(2, 0));
        for (int i = n - 1; i >= 0; --i) {
            for (int canBuy : {0, 1}) {
                int res = 0;
                if (canBuy) {
                    res = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
                } else {
                    res = max(prices[i] + dp[i + 1][1], dp[i + 1][0]);
                }

                dp[i][canBuy] = res;
            }
        }

        return dp[0][1];
    }
};