class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 1);
        int res = 1;
        for (int idx = 0; idx < n; ++idx) {
            for (int prevIdx = 0; prevIdx < idx; ++prevIdx) {
                if (nums[prevIdx] < nums[idx]) {
                    dp[idx] = max(dp[idx], 1 + dp[prevIdx]);
                    res = max(res, dp[idx]);
                }
            }
        }

        return res;
    }
};
