class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> res;
        vector<int> temp;
        function<void(int, int)> dfs = [&] (int idx, int curSum) {
            if (curSum == target) {
                res.push_back(temp);
                return;
            }

            for (auto i = idx; i < n; ++i) {
                if (i > idx and candidates[i - 1] == candidates[i]) {
                    continue;
                }

                if (curSum + candidates[i] <= target) {
                    temp.push_back(candidates[i]);
                    dfs(i + 1, curSum + candidates[i]);
                    temp.pop_back();
                }
            }
        };
        
        sort(candidates.begin(), candidates.end());
        dfs(0, 0);
        return res;
    }
};
