class Solution {
public:
    int solver(vector<int>& nums, int l, int r, int target) {
        if (l > r) {
            return -1;
        }

        int mid = (l + r) / 2;
        if (target == nums[mid]) {
            return mid;
        } else if (target < nums[mid]) {
            return solver(nums, l, mid - 1, target);
        } else if (target > nums[mid]) {
            return solver(nums, mid + 1, r, target);
        }
    }

    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        return solver(nums, l, r, target);
    }
};
