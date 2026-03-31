class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 0, maxProfit = 0;
        while (r < prices.size()) {
            while (prices[r] < prices[l]) {
                l++;
            }

            maxProfit = max(maxProfit, prices[r] - prices[l]);
            r++;
        }
        return maxProfit;
    }
};
