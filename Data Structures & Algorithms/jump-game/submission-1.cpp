class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        function<bool(int)> dfs = [&] (int i) {
            if (i >= nums.size() - 1) {
                return true;
            }

            if (dp[i] != -1) {
                return static_cast<bool>(dp[i]);
            }

            int end = min(static_cast<int>(nums.size()) - 1, i + nums[i]);
            for (int j = i + 1; j <= end; ++j) {
                if (dfs(j)) {
                    dp[i] = 1;
                    return true;
                }
            }

            dp[i] = 0;
            return false;
        };

        return dfs(0);
    }
};
