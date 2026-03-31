class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 2);
        int prev1 = 0, prev2 = 0;
        for (int i = n - 1; i >= 0; --i) {
            int cur = max(nums[i] + prev1, prev2);
            prev1 = prev2;
            prev2 = cur;
        }

        return prev2;
    }
};
