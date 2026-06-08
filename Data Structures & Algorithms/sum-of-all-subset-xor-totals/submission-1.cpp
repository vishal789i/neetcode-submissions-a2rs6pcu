class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int totalSum = 0, sum = 0;
        function<void(int)> backtrack = [&] (int i) {
            if (i == nums.size()) {
                totalSum += sum;
                return;
            }

            backtrack(i + 1);
            sum ^= nums[i];
            backtrack(i + 1);
            sum ^= nums[i];
        };

        backtrack(0);
        return totalSum;
    }
};