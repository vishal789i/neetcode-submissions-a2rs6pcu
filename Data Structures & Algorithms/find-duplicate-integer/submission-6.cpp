class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (auto num : nums) {
            auto idx = abs(num);
            if (nums[idx - 1] < 0) {
                return abs(num);
            }

            nums[idx - 1] *= -1;
        }

        return -1;
    }
};
