class Solution {
public:
    int dfs(vector<int>& nums, int n, vector<int>& dp) {
        if (n < 0) {
            return 0;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        return dp[n] = max(nums[n] + dfs(nums, n - 2, dp), dfs(nums, n - 1, dp));
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> numsWithoutFirstHouse(nums.begin() + 1, nums.end());
        vector<int> numsWithoutLastHouse(nums.begin(), nums.end() - 1);

        int n1 = numsWithoutFirstHouse.size();
        int n2 = numsWithoutLastHouse.size();
        vector<int> dp1(n, -1), dp2(n, -1);

        return max(dfs(numsWithoutFirstHouse, n1 - 1, dp1), dfs(numsWithoutLastHouse, n2 - 1, dp2));
    }
};
