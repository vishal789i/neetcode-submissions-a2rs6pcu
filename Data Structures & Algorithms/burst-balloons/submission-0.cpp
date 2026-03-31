class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector dp(n + 1, vector(n + 1, -1));
        function<int(int, int)> f = [&] (int i, int j) {
            if (i + 1 == j) {
                return 0; // no balloon in between
            }

            if (dp[i][j] != -1) {
                return dp[i][j];
            }

            int res = INT_MIN;
            for (int k = i + 1; k <= j - 1 ; k++) {
                res = max(res, f(i, k) + (nums[i] * nums[k] * nums[j]) + f(k, j));
            }

            return dp[i][j] = res;
        };


        return f(0, n - 1);
    }
};
