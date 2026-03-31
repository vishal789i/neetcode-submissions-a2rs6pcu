class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        map<pair<int, bool>, int> dp;
        function<int(int, bool)> dfs = [&] (int i, bool isSubArrayStarted) {
            if (i == nums.size()) {
                return isSubArrayStarted ? 0 : INT_MIN;
            }

            if (dp.contains({i, isSubArrayStarted})) {
                return dp.at({i, isSubArrayStarted});
            }

            if (isSubArrayStarted) {
                return dp[{i, isSubArrayStarted}] = max(0, nums[i] + dfs(i + 1, true));
            }

            return dp[{i, isSubArrayStarted}] = max(dfs(i + 1, false), nums[i] + dfs(i + 1, true));
        };

        return dfs(0, false);
    }
};
