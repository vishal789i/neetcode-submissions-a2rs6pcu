class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        function<void(int)> solve = [&] (int idx) {
            if (idx == nums.size()) {
                ans.push_back(nums);
                return;
            }

            for (int i = idx; i < nums.size(); ++i) {
                swap(nums[i], nums[idx]);
                solve(idx + 1);
                swap(nums[i], nums[idx]);
            }
        };

        solve(0);
        return ans;
    }
};
