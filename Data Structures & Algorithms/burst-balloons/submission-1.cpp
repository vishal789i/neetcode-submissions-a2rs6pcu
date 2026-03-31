class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector dp(n + 1, vector(n + 1, 0));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                if (i + 1 == j) {
                    continue;
                }

                int res = INT_MIN;
                for (int k = i + 1; k <= j - 1 ; k++) {
                    res = max(res, dp[i][k] + (nums[i] * nums[k] * nums[j]) + dp[k][j]);
                }

                dp[i][j] = res;
            }
        }

        return dp[0][n - 1];
    }
};
