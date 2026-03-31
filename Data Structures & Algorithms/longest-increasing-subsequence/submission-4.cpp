class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        function<int(int)> dfs = [&] (int i) {
            int res = 1;
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] > nums[i]) {
                    res = max(res, 1 + dfs(j));
                }
            }

            return res;
        };

        int res = 0;
        for (int i = 0; i < n; ++i) {
            res = max(res, dfs(i));
        }

        return res;
    }
};
