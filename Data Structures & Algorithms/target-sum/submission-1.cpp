class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> mp;

        function<int(int, int)> dfs = [&] (int idx, int sum) {
            if (idx == nums.size()) {
                return sum == 0 ? 1 : 0;
            }

            auto key = to_string(idx) + to_string(sum);
            if (mp.count(key)) {
                return mp[key];
            }

            return mp[key] = dfs(idx + 1, sum + nums[idx]) + dfs(idx + 1, sum - nums[idx]);
        };

        return dfs(0, target);
    }
};
