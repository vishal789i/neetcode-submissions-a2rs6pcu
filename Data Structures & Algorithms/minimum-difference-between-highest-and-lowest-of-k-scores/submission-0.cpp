class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = 0, res = INT_MAX;
        while (r < nums.size()) {
            if (r - l + 1 == k) {
                res = min(res, nums[r] - nums[l]);
                l++;
            }

            r++;
        }

        return res;
    }
};