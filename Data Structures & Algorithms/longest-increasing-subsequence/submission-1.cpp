class Solution {
public:
    int dfs(vector<int>& nums, int idx, int prevIdx) {
        if (idx == nums.size()) {
            return 0;
        }

        int res = dfs(nums, idx + 1, prevIdx);
        if (prevIdx == -1 or nums[prevIdx] < nums[idx]) {
            res = max(res, 1 + dfs(nums, idx + 1, idx));
        }

        return res;
    }

    int lengthOfLIS(vector<int>& nums) {
        return dfs(nums, 0, -1);
    }
};
