class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        function<void(int, vector<int>&)> solve = [&] (int i, vector<int>& op) {
            if (i == nums.size()) {
                ans.push_back(op);
                return;
            }

            op.push_back(nums[i]);
            solve(i + 1, op);
            op.pop_back();

            while (i + 1 < nums.size() and nums[i] == nums[i + 1]) {
                ++i;
            }

            solve(i + 1, op);
        };

        vector<int> op;
        sort(nums.begin(), nums.end());
        solve(0, op);
        return ans;
    }
};
