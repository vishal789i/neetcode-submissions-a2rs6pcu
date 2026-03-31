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

            for (auto i = idx; i < nums.size(); ++i) {
                if (curSum + nums[i] <= target) {
                    temp.push_back(nums[i]);
                    dfs(i, curSum + nums[i]);
                    temp.pop_back();
                }
            }
        };

        dfs(0, 0);
        return res;
    }
};
