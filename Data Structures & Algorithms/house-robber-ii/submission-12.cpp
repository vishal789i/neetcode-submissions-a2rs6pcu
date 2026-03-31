class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        vector<int> nums1(nums.begin(), nums.end() - 1);
        vector<int> nums2(nums.begin() + 1, nums.end());
        
        int n = nums1.size();
        vector<int> dp(n + 1, -1);

        function<int(vector<int>&, int)> dfs = [&] (vector<int>& nums, int i) {
            if (i >= n) {
                return 0;
            }

            if (dp[i] != -1) {
                return dp[i];
            }

            return dp[i] = max(nums[i] + dfs(nums, i + 2), dfs(nums, i + 1));
        };

        int nums1Cost = dfs(nums1, 0);

        dp.assign(n, -1);
        int nums2Cost = dfs(nums2, 0);

        return max(nums1Cost, nums2Cost);
    }
};
