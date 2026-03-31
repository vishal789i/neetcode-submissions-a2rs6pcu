class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> res;
        sort(begin(candidates), end(candidates));
        function<void(int, vector<int>&, int)> f = [&] (int i, vector<int>& op, int curSum) {
            if (curSum == target) {
                res.push_back(op);
                return;
            }

            for (int j = i; j < n; ++j) {
                if (j > i and candidates[j - 1] == candidates[j]) {
                    continue;
                }

                if (curSum + candidates[j] <= target) {
                    op.push_back(candidates[j]);
                    f(j + 1, op, curSum + candidates[j]);
                    op.pop_back();
                }
            }
        };

        vector<int> op;
        f(0, op, 0);
        return res;
    }
};
