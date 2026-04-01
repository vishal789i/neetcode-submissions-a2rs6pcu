class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;

        function<void(vector<int>&)> f = [&] (vector<int>& op) {
            if (op.size() == nums.size()) {
                res.insert(op);
                return;
            }

            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] == INT_MAX) {
                    continue;
                }

                int temp = nums[i];
                nums[i] = INT_MAX;
                op.push_back(temp);
                f(op);
                op.pop_back();
                nums[i] = temp;
            }
        };

        vector<int> op;
        f(op);
        return vector<vector<int>>(res.begin(), res.end());
    }
};