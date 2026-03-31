class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        function<int(int)> dfs = [&] (int i) {
            if (i >= n) {
                return 0;
            }

            if (dp[i] != -1) {
                return dp[i];
            }

            return dp[i] = max(nums[i] + dfs(i + 2), dfs(i + 1));
        };

        return dfs(0);
    }
};
