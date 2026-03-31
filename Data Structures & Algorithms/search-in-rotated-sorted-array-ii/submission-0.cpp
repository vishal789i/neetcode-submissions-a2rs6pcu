class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (target == nums[m]) {
                return true;
            }

            if (nums[l] == nums[m]) {
                l++;
                continue;
            }

            if (nums[l] <= nums[m]) {
                if (target < nums[l] or target > nums[m]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            } else { // l > m
                if (target > nums[r] or target < nums[m]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
        }

        return false;
    }
};
