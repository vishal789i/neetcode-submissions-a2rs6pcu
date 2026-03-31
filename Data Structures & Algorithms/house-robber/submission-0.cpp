class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        function<int(int)> dfs = [&] (int n) {
            if (n >= nums.size()) {
                return 0;
            }

            if (dp[n] != -1) {
                return dp[n];
            }

            int neighborHouseLoot = dfs(n+1);
            int neighborsNeighborHouseLoot = nums[n] + dfs(n+2);

            return dp[n] = max(neighborHouseLoot, neighborsNeighborHouseLoot);
        };

        return dfs(0);
    }
};
