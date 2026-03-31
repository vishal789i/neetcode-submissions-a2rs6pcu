class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector prev(n + 1, 0), cur(n + 1, 0);
        for (int idx = n - 1; idx >= 0; --idx) {
            for (int prevIdx = idx - 1; prevIdx >= -1; --prevIdx) {
                int res = prev[prevIdx + 1];
                if (prevIdx == -1 or nums[idx] > nums[prevIdx]) { //op as we are going to n - 1 to 0
                    res = max(res, 1 + prev[idx + 1]);
                }

                cur[prevIdx + 1] = res;
            }

            prev = cur;
        }

        return prev[-1 + 1];
    }
};
