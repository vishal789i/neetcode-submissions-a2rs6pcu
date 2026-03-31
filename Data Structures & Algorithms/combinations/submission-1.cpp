class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            nums[i] = i + 1;
        }

        vector<vector<int>> res;
        function<void(int, vector<int>&)> f = [&] (int i, vector<int>& op) {
            if (op.size() == k) {
                res.push_back(op);
                return;
            }

            if (i == n) {
                return;
            }

            // not pick
            f(i + 1, op);

            op.push_back(nums[i]);
            f(i + 1, op);
            op.pop_back();
        };

        vector<int> op;
        f(0, op);
        return res;
    }
};