class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        auto sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) {
            return false;
        }

        auto subsetSum = sum / k;
        sort(nums.rbegin(), nums.rend());
        vector<int> sums(k);
        vector<bool> vis(nums.size(), false);
        function<bool(int)> dfs = [&] (int i) {
            if (i == nums.size()) {
                return true;
            }

            for (int j = 0; j < k; ++j) {
                if (sums[j] + nums[i] > subsetSum) {
                    continue;
                }

                sums[j] += nums[i];
                if (dfs(i + 1)) {
                    return true;
                }

                sums[j] -= nums[i];
                if (sums[j] == 0) break;
            }

            return false;
        };

        return dfs(0);
    }
};