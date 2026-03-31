class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        function<int(int)> dfs = [&] (int sum) {
            if (sum == target) {
                return 1;
            }

            if (sum > target) {
                return 0;
            }

            if (dp[sum] != -1) {
                return dp[sum];
            }

            int res = 0;
            for (auto i = 0; i < nums.size(); ++i) {
                res += dfs(sum + nums[i]);
            }
            return dp[sum] = res;
        };

        return dfs(0);
    }
};