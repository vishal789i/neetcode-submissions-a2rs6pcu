class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int res = 0;
        function<void(int, int)> dfs = [&] (int i, int curSum) {
            if (i == nums.size()) {
                res += curSum;
                return;
            }

            dfs(i + 1, curSum);
            dfs(i + 1, curSum ^ nums[i]);
        };
        
        dfs(0, 0);
        return res;
    }
};