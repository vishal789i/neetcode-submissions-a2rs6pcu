class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        function<void(int, int)> dfs = [&] (int idx, int curSum) {
            if (curSum == target) {
                res.push_back(temp);
                return;
            }

            if (idx >= nums.size() or curSum > target) {
                return;
            }

            temp.push_back(nums[idx]);
            dfs(idx, curSum + nums[idx]);
            temp.pop_back();

            dfs(idx + 1, curSum);
        };

        dfs(0, 0);
        return res;
    }
};
