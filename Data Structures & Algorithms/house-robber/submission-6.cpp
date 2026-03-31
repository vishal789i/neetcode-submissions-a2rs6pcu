class Solution {
public:
    int rob(vector<int>& nums) {
        map<int, int> dp;
        function<int(int)> dfs = [&] (int i) {
            if (i < 0) {
                return 0;
            }

            if (dp.contains(i)) {
                return dp[i];
            }

            return dp[i] = max(nums[i] + dfs(i - 2), dfs(i - 1));
        };

        return dfs(nums.size() - 1);
    }
};
