class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        int minEle = INT_MAX;
        while (l <= r) {
            if (nums[l] < nums[r]) {
                minEle = min(minEle, nums[l]);
                break;
            }
            int mid = l + (r - l)/2;
            minEle = min(minEle, nums[mid]);
            if (nums[l] <= nums[mid]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return minEle;
    }
};
