class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        auto atmost = [&nums] (int g) {
            if (g < 0) {
                return 0;
            }

            int l = 0, sum = 0, res = 0;
            for (int r = 0; r < nums.size(); ++r) {
                sum += nums[r];
                while (sum > g) {
                    sum -= nums[l++];
                }

                // sum <= goal
                res += r - l + 1;
            }

            return res;
        };

        return atmost(goal) - atmost(goal - 1);
    }
};