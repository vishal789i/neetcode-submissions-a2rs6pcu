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

            if (idx >= n or curSum > target) {
                return;
            }

            temp.push_back(candidates[idx]);
            dfs(idx + 1, curSum + candidates[idx]);
            temp.pop_back();

            while ((idx + 1) < n and candidates[idx] == candidates[idx + 1]) {
                idx++;
            }
            
            dfs(idx + 1, curSum);
        };
        
        sort(candidates.begin(), candidates.end());
        dfs(0, 0);
        return res;
    }
};
