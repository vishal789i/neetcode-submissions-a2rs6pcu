class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector prev(2, 0), cur(2, 0);
        for (int i = n - 1; i >= 0; --i) {
            for (int canBuy : {0, 1}) {
                int res = 0;
                if (canBuy) {
                    res = max(-prices[i] + prev[0], prev[1]);
                } else {
                    res = max(prices[i] + prev[1], prev[0]);
                }

                cur[canBuy] = res;
            }

            prev = cur;
        }

        return prev[1];
    }
};