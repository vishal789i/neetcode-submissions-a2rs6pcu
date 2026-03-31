class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target, -1);
        function<int(int)> dfs = [&] (int curSum) {
            if (curSum == target) {
                return 1;
            } else if (curSum > target) {
                return 0;
            }

            if (dp[curSum] != -1) {
                return dp[curSum];
            }

            int res = 0;
            for (int j = 0; j < nums.size(); ++j) {
                res += dfs(curSum + nums[j]);
            }

            return dp[curSum] = res;
        };

        return dfs(0);
    }
};