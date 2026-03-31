class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (auto& num : nums) {
            if (num < 0) {
                num = 0;
            }
        }

        for (auto& num : nums) {
            int val = abs(num);
            int idx = val - 1;
            if (0 <= idx and idx < n) {
                if (nums[idx] > 0) {
                    nums[idx] *= -1;
                } else if (nums[idx] == 0) {
                    nums[idx] = -1 * (n + 1);   // change it to a negative val that does not affect solution as eg. -6
                }
            }
        }

        for (int i = 1; i <= n; ++i) {
            if (nums[i - 1] >= 0) {
                return i;
            }
        }

        return n + 1;
    }
};