class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        function<int(int)> dfs = [&] (int i) {
            if (i == nums.size()) {
                return 0;
            }

            int len = 1;
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[j] > nums[i]) {
                    len = max(len, 1 + dfs(j));
                }
            }

            return len;
        };

        int res = 1;
        for (int i = 0; i < nums.size(); ++i) {
            res = max(res, dfs(i));
        }

        return res;
    }
};
