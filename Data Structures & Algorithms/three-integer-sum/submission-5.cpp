class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 and nums[i-1] == nums[i]) {
                continue;
            }

            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[l] + nums[i] + nums[r];
                if (sum > 0) {
                    r--;
                } else if (sum < 0) {
                    l++;
                } else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;

                    while (l > 0 and nums[l - 1] == nums[l]) {
                        l++;
                    }

                    while (r > 0 and nums[r] == nums[r + 1]) {
                        r--;
                    }
                }
            }
        }

        return ans;
    }
};
