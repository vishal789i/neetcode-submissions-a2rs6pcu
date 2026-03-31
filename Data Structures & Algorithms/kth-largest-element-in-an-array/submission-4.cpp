class Solution {
public:
    int partition(vector<int>& nums, int l, int r) {
        int pivot = nums[r];
        int i = l;
        for (int j = l; j < r; ++j) {
            if (nums[j] < pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[r]);
        return i;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;
        k = nums.size() - k;

        while (l <= r) {
            int pivotIdx = partition(nums, l, r);

            if (pivotIdx == k) {
                return nums[pivotIdx];
            } else if (pivotIdx < k) {
                l = pivotIdx + 1;
            } else {
                r = pivotIdx - 1;
            }
        }

        return -1;
    }
};