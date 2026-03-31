class Solution {
public:
    int dfs(vector<int>& nums, int idx, int prevIdx, vector<vector<int>>& dp) {
        if (idx == nums.size()) {
            return 0;
        }

        if (dp[idx][prevIdx + 1] != -1) {
            return dp[idx][prevIdx + 1];
        }

        int res = dfs(nums, idx + 1, prevIdx, dp);
        if (prevIdx == -1 or nums[prevIdx] < nums[idx]) {
            res = max(res, 1 + dfs(nums, idx + 1, idx, dp));
        }

        return dp[idx][prevIdx + 1] = res;
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, -1));
        return dfs(nums, 0, -1, dp);
    }
};
