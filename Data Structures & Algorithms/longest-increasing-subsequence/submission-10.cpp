class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector dp(n + 1, vector(n + 1, -1));
        function<int(int, int)> f = [&] (int prevIdx, int idx) {
            if (idx == n) {
                return 0;
            }

            if (dp[prevIdx + 1][idx] != -1) {
                return dp[prevIdx + 1][idx];
            }

            int res = f(prevIdx, idx + 1);
            if (prevIdx == -1 or nums[idx] > nums[prevIdx]) { //op as we are going to n - 1 to 0
                res = max(res, 1 + f(idx, idx + 1));
            }

            return dp[prevIdx + 1][idx] = res;
        };

        return f(-1, 0);
    }
};
