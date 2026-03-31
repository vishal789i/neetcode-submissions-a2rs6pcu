class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, int target, int idx, int currSum, vector<int>& op) {
        if (currSum == target) {
            ans.push_back(op);
            return;
        }

        for (int i = idx; i < nums.size(); ++i) {
            if (currSum + nums[i] <= target) {
                op.push_back(nums[i]);
                solve(nums, target, i, currSum + nums[i], op);
                op.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> op;
        solve(nums, target, 0, 0, op);
        return ans;
    }
};
