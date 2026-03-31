class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 2);
        for (int i = n - 1; i >= 0; --i) {
            int pick = nums[i] + dp[i + 2];
            int notPick = dp[i + 1];
            dp[i] = max(pick, notPick);
        }

        return dp[0];
    }
};
