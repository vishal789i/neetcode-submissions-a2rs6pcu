class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int res = 0;
        for (int i = 1; i < prices.size(); ++i) {
            int cost = prices[i] - mini;
            res = max(res, cost);
            mini = min(mini, prices[i]);
        }

        return res;
    }
};
