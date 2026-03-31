class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            auto idx = abs(nums[i]);
            if (nums[idx - 1] < 0) {
                return abs(nums[i]);
            }

            nums[idx - 1] *= -1;
        }

        return -1;
    }
};
