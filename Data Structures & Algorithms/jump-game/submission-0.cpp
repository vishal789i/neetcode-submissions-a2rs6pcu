class Solution {
public:
    bool canJump(vector<int>& nums) {
        function<bool(int)> dfs = [&] (int i) {
            if (i >= nums.size() - 1) {
                return true;
            }

            int end = min(static_cast<int>(nums.size()) - 1, i + nums[i]);
            for (int j = i + 1; j <= end; ++j) {
                if (dfs(j)) {
                    return true;
                }
            }

            return false;
        };

        return dfs(0);
    }
};
