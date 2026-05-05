class Solution {
public:
    int rob(vector<int>& nums) {
        vector dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[1], dp[0]);
        for (int i = 2; i < nums.size(); ++i) {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }

        return dp[nums.size() - 1];
    }
};
