class Solution {
public:
    void merge(vector<int>& nums, int l, int m, int r) {
        int i = l, j = m + 1;
        vector<int> temp;
        while (i <= m and j <= r) {
            if (nums[i] < nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }

        while (i <= m) {
            temp.push_back(nums[i++]);
        }

        while (j <= r) {
            temp.push_back(nums[j++]);
        }

        for (int i = l; i <= r; ++i) {
            nums[i] = temp[i - l];
        }
    }

    void mergeSort(vector<int>& nums, int l, int r) {
        if (l < r) {
            int m = l + (r - l)/2;
            mergeSort(nums, l, m);
            mergeSort(nums, m + 1, r);
            merge(nums, l, m, r);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};