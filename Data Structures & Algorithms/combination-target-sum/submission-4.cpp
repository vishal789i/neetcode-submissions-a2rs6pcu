class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        int curSum = 0;
        vector<int> temp;
        function<void(int)> dfs = [&] (int idx) {
            if (curSum == target) {
                res.push_back(temp);
                return;
            }

            for (int i = idx; i < n; ++i) {
                if (curSum + nums[i] <= target) {
                    curSum += nums[i];
                    temp.push_back(nums[i]);
                    dfs(i);
                    curSum -= nums[i];
                    temp.pop_back();
                }
            }
        };

        dfs(0);
        return res;
    }
};
