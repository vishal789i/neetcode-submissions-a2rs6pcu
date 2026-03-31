class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 0, maxProfit = 0;
        while (r < prices.size()) {
            while (prices[r] < prices[l]) {
                l++;
            }

            int currProfit = prices[r] - prices[l];
            maxProfit = max(maxProfit, currProfit);

            r++;
        }
        return maxProfit;
    }
};
