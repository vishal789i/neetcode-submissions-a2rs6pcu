class Solution {
public:
    int dfs(vector<int>& nums, int i) {
        if (i == nums.size()) {
            return 0;
        }

        int res = 1;
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[j] > nums[i]) {
                res = max(res, 1 + dfs(nums, j));
            }
        }

        return res;
    }

    int lengthOfLIS(vector<int>& nums) {
        int res = 1;
        for (int i = 0; i < nums.size(); ++i) {
            res = max(res, dfs(nums, i));
        }
        
        return res;
    }
};
