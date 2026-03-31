class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l)/2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[l] <= nums[mid]) {   // left section
                if (target < nums[l] or target > nums[mid]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            } else {
                if (target > nums[r] or target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
        return -1;
    }
};
