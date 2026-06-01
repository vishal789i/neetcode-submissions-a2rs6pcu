class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, res = 0;
        for (int r = 0; r < prices.size(); ++r) {
            int profit = prices[r] - prices[l];
            if (profit < 0) {
                l = r;
            }

            res = max(res, profit);
        }

        return res;
    }
};
