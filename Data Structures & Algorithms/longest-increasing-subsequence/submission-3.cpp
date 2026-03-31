class Solution {
public:
    int dfs(vector<int>& nums, int idx, vector<int>& dp) {
        if (dp[idx] != -1) {
            return dp[idx];
        }

        int res = 1;
        for (int nextIdx = idx + 1; nextIdx < nums.size(); ++nextIdx) {
            if (nums[idx] < nums[nextIdx]) {
                res = max(res, 1 + dfs(nums, nextIdx, dp));
            }
        }

        return dp[idx] = res;
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        int res = 1;
        for (int idx = 0; idx < nums.size(); ++idx) {
            res = max(res, dfs(nums, idx, dp));
        }

        return res;
    }
};
