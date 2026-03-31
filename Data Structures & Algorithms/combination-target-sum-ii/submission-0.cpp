class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        function<void(int, int, vector<int>&)> solve = [&] (int i, int currSum, vector<int>& op) {
            if (currSum == target) {
                ans.push_back(op);
                return;
            }

            if (i >= candidates.size() or currSum > target) {
                return;
            }

            op.push_back(candidates[i]);
            solve(i + 1, currSum + candidates[i], op);
            op.pop_back();

            while (i < candidates.size() and candidates[i] == candidates[i + 1]) {
                ++i;
            }

            solve(i + 1, currSum, op);
        };

        sort(candidates.begin(), candidates.end());
        vector<int> op;
        solve(0, 0, op);
        return ans;
    }
};
