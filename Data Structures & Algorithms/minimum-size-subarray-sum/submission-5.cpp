class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0;
        int curSum = 0, res = INT_MAX;
        while (r < nums.size()) {
            curSum += nums[r];
            while (curSum >= target) {
                res = min(res, r - l + 1);
                curSum -= nums[l];
                l++;
            }

            r++;
        }

        return res == INT_MAX ? 0 : res;
    }
};