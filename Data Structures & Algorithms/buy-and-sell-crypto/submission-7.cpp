class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 0, maxProfit = 0;
        while (r < prices.size()) {
            if (prices[l] < prices[r]) {
                maxProfit = max(maxProfit, prices[r] - prices[l]);
            } else if (prices[l] > prices[r]) {
                while (prices[l] > prices[r]) {
                    l++;
                }
            }
            r++;
        }
        return maxProfit;
    }
};
