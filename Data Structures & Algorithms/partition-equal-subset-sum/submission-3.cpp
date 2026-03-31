class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) {
            return false;
        }

        sum /= 2;
        function<bool(int, int)> dfs = [&] (int i, int curSum) {
            if (i == nums.size()) {
                if (curSum == sum) {
                    return true;
                }

                return false;
            }

            return dfs(i + 1, curSum + nums[i]) or dfs(i + 1, curSum);
        };

        return dfs(0, 0);
    }
};
