class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int profit = 0;
        for (int r = 0; r < prices.size(); ++r) {
            while (prices[l] > prices[r]) {
                l++;
            }
            profit = max(profit, prices[r] - prices[l]);
        }

        return profit;
    }
};
