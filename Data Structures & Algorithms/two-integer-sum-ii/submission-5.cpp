class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (true) {
            int sum = nums[l] + nums[r];
            if (sum < target) {
                l++;
            } else if (sum > target) {
                r--;
            } else {
                return {l + 1, r + 1};
            }
        }

        return {-1, -1};
    }
};
