class Solution {
public:
    bool isSubSetSumPresent(vector<int>& nums, int idx, vector<vector<int>>& dp, int sum) {
        if (idx >= nums.size() or sum < 0) {
            return false;
        }

        if (sum == 0) {
            return true;
        }

        if (dp[idx][sum] != -1) {
            return dp[idx][sum];
        }

        return dp[idx][sum] = isSubSetSumPresent(nums, idx + 1, dp, sum - nums[idx]) or isSubSetSumPresent(nums, idx + 1, dp, sum);
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) {
            return false;
        }

        vector<vector<int>> dp(nums.size(), vector<int>(sum + 1, -1));
        return isSubSetSumPresent(nums, 0, dp, sum/2);
    }
};