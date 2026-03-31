class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(2, INT_MIN));
        return dfs(0, false, nums, dp);
    }

    int dfs(int i, bool isSubArrayStarted, vector<int>& nums, vector<vector<int>>& dp) {
        if (i == nums.size()) {
            return isSubArrayStarted ? 0 : INT_MIN;
        }

        if (dp[i][isSubArrayStarted] != INT_MIN) {
            return dp[i][isSubArrayStarted];
        }

        if (isSubArrayStarted) {
            return dp[i][isSubArrayStarted] = max(0, nums[i] + dfs(i + 1, true, nums, dp));
        }

        return dp[i][isSubArrayStarted] = max(dfs(i + 1, false, nums, dp), nums[i] + dfs(i + 1, true, nums, dp));
    };
};
