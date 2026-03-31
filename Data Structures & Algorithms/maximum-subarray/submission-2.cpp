class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0;
        int res = INT_MIN;
        for (auto n : nums) {
            curSum += n;
            res = max(res, curSum);
            if (curSum < 0) {
                curSum = 0;
            }
        }

        return res;
    }
};
