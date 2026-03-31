class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 and nums[i - 1] == nums[i]) {
                continue;
            }

            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j < k and nums[j - 1] == nums[j]) {
                        j++;
                    }

                    while (j < k and nums[k] == nums[k + 1]) {
                        k--;
                    }
                } else if (sum > 0) {
                    k--;
                } else if (sum < 0) {
                    j++;
                }
            }
        }

        return res;
    }
};
