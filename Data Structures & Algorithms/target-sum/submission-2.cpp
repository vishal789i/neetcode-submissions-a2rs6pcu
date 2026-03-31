class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int, int>, int> dp;
        function<int(int, int)> dfs = [&] (int i, int curSum) {
            if (i == nums.size()) {
                if (curSum == target) {
                    return 1;
                }

                return 0;
            }

            if (dp.contains({i, curSum})) {
                return dp[{i, curSum}];
            }

            return dp[{i, curSum}] = dfs(i + 1, curSum + nums[i]) + dfs(i + 1, curSum - nums[i]);
        };

        return dfs(0, 0);
    }
};
