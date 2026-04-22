class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int j = 0;
        while (j < n - 2) {
            int l = j + 1, r = n - 1;
            while (l < r) {
                int sum = nums[j] + nums[l] + nums[r];
                if (sum == 0) {
                    res.push_back({nums[j], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < r and nums[l] == nums[l - 1]) {
                        l++;
                    }

                    while (l < r and nums[r] == nums[r + 1]) {
                        r--;
                    }
                } else if (sum > 0) {
                    r--;
                } else {
                    l++;
                }
            }

            j++;
            while (j < n - 2 and nums[j] == nums[j - 1]) {
                j++;
            }
        }

        return res;
    }
};