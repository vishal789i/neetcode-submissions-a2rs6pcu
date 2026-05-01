class Solution {
    int getMaxSum(vector<int>& nums) {
        int maxSum = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            sum = max(nums[i], sum + nums[i]);
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }

    int getMinSum(vector<int>& nums) {
        int minSum = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            sum = min(nums[i], sum + nums[i]);
            minSum = min(minSum, sum);
        }

        return minSum;
    }
    
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int maxSum = getMaxSum(nums);
        int minSum = getMinSum(nums);
        int circularSum = totalSum - minSum;
        if (maxSum > 0) {
            return max(maxSum, circularSum);
        }

        return maxSum;
    }
};