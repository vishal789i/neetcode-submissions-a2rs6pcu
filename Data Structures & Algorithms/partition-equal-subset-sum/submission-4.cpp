class Solution {
    bool dfs(vector<int>& nums, int sum, int i) {
        if (i == nums.size()) {
            if (sum == 0) {
                return true;
            }

            return false;
        }

        return dfs(nums, sum, i + 1) or dfs(nums, sum - nums[i], i + 1);
    }

public:
    bool canPartition(vector<int>& nums) {
        auto sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) {
            return false;
        }
        
        return dfs(nums, sum / 2, 0);
    }
};
