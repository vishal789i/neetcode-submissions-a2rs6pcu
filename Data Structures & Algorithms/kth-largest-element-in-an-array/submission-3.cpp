class Solution {
public:
    int partitionAndGetPivotIdx(vector<int>& nums, int l, int r) {
        int i = l;
        for (int j = l; j < r; ++j) {
            if (nums[j] < nums[r]) {
                swap(nums[j], nums[i]);
                ++i;
            }
        }
        swap(nums[i], nums[r]);
        return i;
    }

    int qs(vector<int>& nums, int l, int r, int k) {
        if (l == r) return nums[l];

        int pivotIdx = partitionAndGetPivotIdx(nums, l, r);
        
        if (k == pivotIdx) {
            return nums[k];
        } else if (k < pivotIdx) {
            return qs(nums, l, pivotIdx - 1, k);
        } else {
            return qs(nums, pivotIdx + 1, r, k);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        return qs(nums, 0, nums.size() - 1, nums.size() - k);
    }
};
