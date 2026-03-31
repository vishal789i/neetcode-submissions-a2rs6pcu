class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        function<void(vector<int>&, int, int)> solve = [&] (vector<int>& op, int idx, int currSum) {
            if (currSum == target) {
                ans.push_back(op);
                return;
            }

            for (int i = idx; i < candidates.size(); ++i) {
                if (i > idx and candidates[i-1] == candidates[i]) {
                    continue;
                }
                
                if (candidates[i] + currSum <= target) {
                    op.push_back(candidates[i]);
                    solve(op, i + 1, candidates[i] + currSum);
                    op.pop_back();
                }
            }
        };

        vector<int> op;
        sort(candidates.begin(), candidates.end());
        solve(op, 0, 0);
        return ans;
    }
};
