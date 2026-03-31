class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        function<int(int)> dfs = [&] (int i) {
            if (dp[i] != -1) {
                return dp[i];
            }
            
            int res = 1;
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] > nums[i]) {
                    res = max(res, 1 + dfs(j));
                }
            }

            return dp[i] = res;
        };

        int res = 0;
        for (int i = 0; i < n; ++i) {
            res = max(res, dfs(i));
        }

        return res;
    }
};
