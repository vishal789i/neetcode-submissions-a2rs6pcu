class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        set<vector<int>> res;
        function<void(int, vector<int>&, int)> f = [&] (int i, vector<int>& op, int sum) {
            if (sum == target) {
                res.insert(op);
                return;
            }

            for (int j = i; j < nums.size(); ++j) {
                if (nums[j] + sum <= target) {
                    op.push_back(nums[j]);
                    f(j, op, sum + nums[j]);
                    op.pop_back();
                }
            }
        };

        vector<int> op;
        f(0, op, 0);
        return vector<vector<int>>(res.begin(), res.end());
    }
};
