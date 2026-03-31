class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector dp(n + 1, vector(n + 1, 0));
        for (int idx = n - 1; idx >= 0; --idx) {
            for (int prevIdx = idx - 1; prevIdx >= -1; --prevIdx) {
                int res = dp[prevIdx + 1][idx + 1];
                if (prevIdx == -1 or nums[idx] > nums[prevIdx]) { //op as we are going to n - 1 to 0
                    res = max(res, 1 + dp[idx + 1][idx + 1]);
                }

                dp[prevIdx + 1][idx] = res;
            }
        }

        return dp[-1 + 1][0];
    }
};
