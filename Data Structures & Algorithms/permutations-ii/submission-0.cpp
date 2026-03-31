class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> res;
        vector<int> op;
        function<void(void)> dfs = [&] () {
            if (op.size() == nums.size()) {
                res.insert(op);
                return;
            }

            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] != INT_MIN) {
                    auto temp = nums[i];
                    nums[i] = INT_MIN;
                    op.push_back(temp);
                    dfs();
                    op.pop_back();
                    nums[i] = temp;
                }
            }
        };

        dfs();
        return vector<vector<int>>(res.begin(), res.end());
    }
};