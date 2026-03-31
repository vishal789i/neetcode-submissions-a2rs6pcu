class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 1, -1);
        function<int(int)> dfs = [&] (int i) {
            if (i >= cost.size()) {
                return 0;
            }

            if (dp[i] != -1) {
                return dp[i];
            }

            return dp[i] = cost[i] + min(dfs(i + 1), dfs(i + 2));
        };

        return min(dfs(0), dfs(1));
    }
};
