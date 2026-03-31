class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int r = 0;
        int sum = nums[0], maxSum = nums[0];
        while (r < nums.size() - 1) {
            if (nums[r] < nums[r + 1]) {
                sum += nums[r + 1];
                maxSum = max(maxSum, sum);
            } else {
                sum = nums[r + 1];
            }

            r++;
        }

        return maxSum;
    }
};