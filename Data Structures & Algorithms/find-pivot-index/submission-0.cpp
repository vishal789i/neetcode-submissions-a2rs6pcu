class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // 0 1 8 11 17 22
        // 27 20 17 11 6 0

        int n = nums.size();
        vector<int> leftSums(n), rightSums(n);
        leftSums[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            leftSums[i] = leftSums[i - 1] + nums[i];
        }

        rightSums[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rightSums[i] = rightSums[i + 1] + nums[i];
        }

        for (int i = 0; i < n; ++i) {
            if (leftSums[i] == rightSums[i]) {
                return i;
            }
        }

        return -1;
    }
};