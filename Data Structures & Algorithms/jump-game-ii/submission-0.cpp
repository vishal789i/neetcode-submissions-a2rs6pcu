class Solution {
public:
    int jump(vector<int>& nums) {
        function<int(int)> dfs = [&] (int i) {
            if (i == nums.size() - 1) {
                return 0;
            }

            if (nums[i] == 0) {
                return 100000;
            }

            int endIdx = min((int)nums.size(), i + nums[i]);
            int res = 100000;
            for (int j = i + 1; j <= endIdx; ++j) {
                res = min(res, 1 + dfs(j));
            }
            return res;
        };

        return dfs(0);
    }
};
