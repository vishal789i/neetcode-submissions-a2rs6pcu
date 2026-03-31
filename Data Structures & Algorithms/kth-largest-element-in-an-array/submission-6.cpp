class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int i = l;
            int& pivotEle = nums[r];
            for (int j = l; j <= r; ++j) {
                if (nums[j] < pivotEle) {
                    swap(nums[i++], nums[j]);
                }
            }

            swap(nums[i], pivotEle);
            if (i == k) {
                return nums[k];
            } else if (i < k) {
               l = i + 1; 
            } else {
                r = i - 1;
            }
        }

        return -1;
    }
};
