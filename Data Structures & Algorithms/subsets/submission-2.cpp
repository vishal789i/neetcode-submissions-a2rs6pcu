class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;

        vector<int> temp;
        function<void(int)> dfs = [&] (int idx) {
            if (idx == n) {
                res.push_back(temp);
                return;
            }

            // choose
            temp.push_back(nums[idx]);
            dfs(idx + 1);
            temp.pop_back();

            // dont choose
            dfs(idx + 1);
        };

        dfs(0);
        return res;
    }
};
