class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(k + 1, -1));
        function<int(int, int)> dfs = [&] (int i, int m) {
            if (i == nums.size()) {
                return m != 0 ? INT_MAX : 0;
            }

            if (m == 0) {
                return INT_MAX;
            }

            if (dp[i][m] != -1) {
                return dp[i][m];
            }

            int curSum = 0, res = INT_MAX;
            for (int j = i; j < nums.size(); ++j) {
                curSum += nums[j];
                res = min(res, max(curSum, dfs(j + 1, m - 1)));
            }

            return dp[i][m] = res;
        };

        return dfs(0, k);
    }
};