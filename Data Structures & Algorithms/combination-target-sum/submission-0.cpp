class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& ip, vector<int>& op, int targetSum, int startIdx, int currSum) {
        if (currSum == targetSum) {
            ans.push_back(op);
            return;
        }

        for (int i = startIdx; i < ip.size(); ++i) {
            if (ip[i] + currSum <= targetSum) {
                op.push_back(ip[i]);
                solve(ip, op, targetSum, i, currSum + ip[i]);
                op.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> op;
        sort(nums.begin(), nums.end());
        solve(nums, op, target, 0, 0);
        return ans;
    }
};
