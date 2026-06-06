class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> op;
        function<void(int)> dfs = [&] (int i) {
            if (i == nums.size()) {
                res.push_back(op);
                return;
            }

            dfs(i + 1);
            op.push_back(nums[i]);
            dfs(i + 1);
            op.pop_back();
        };

        dfs(0);
        return res;
    }
};
