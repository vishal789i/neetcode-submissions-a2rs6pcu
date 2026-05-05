class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;

        vector<int> temp;
        auto dfs = [&] (auto&& self, int idx) {
            if (idx == n) {
                res.push_back(temp);
                return;
            }

            // choose
            temp.push_back(nums[idx]);
            self(self, idx + 1);
            temp.pop_back();

            // dont choose
            self(self, idx + 1);
        };

        dfs(dfs, 0);
        return res;
    }
};
