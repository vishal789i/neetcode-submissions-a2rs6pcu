class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 0, profit = 0, n = prices.size();
        int maxProfit = 0;
        while (r < n) {
            profit = prices[r] - prices[l];
            while (profit < 0) {
                l++;
                profit = prices[r] - prices[l];
            }

            maxProfit = max(maxProfit, profit);
            r++;
        }

        return maxProfit;
    }
};
