class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& ip, vector<int>& op, int currIdx, int targetSum) {
        if (targetSum == 0) {
            ans.push_back(op);
            return;
        }

        if (targetSum < 0 or currIdx >= ip.size()) {
            return;
        }

        op.push_back(ip[currIdx]);
        solve(ip, op, currIdx, targetSum - ip[currIdx]);
        op.pop_back();

        solve(ip, op, currIdx + 1, targetSum);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> op;
        solve(nums, op, 0, target);
        return ans;
    }
};
