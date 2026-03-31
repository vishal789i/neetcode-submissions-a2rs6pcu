class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        function<void(int, vector<int>&, int)> f = [&] (int i, vector<int>& op, int curSum) {
            if (curSum == target) {
                res.push_back(op);
                return;
            }

            if (curSum > target or i >= nums.size()) {
                return;
            }

            // exclude
            f(i + 1, op, curSum);
            //include
            op.push_back(nums[i]);
            f(i, op, curSum + nums[i]);
            op.pop_back();
        };

        vector<int> op;
        f(0, op, 0);
        return res;
    }
};
