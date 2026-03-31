class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int len = 1, maxLen = 1;;
        int r = 0;
        while (r < nums.size() - 1) {
            if (nums[r] < nums[r + 1]) {
                len++;
                maxLen = max(maxLen, len);
            } else {
                len = 1;
            }

            r++;
        }

        r = 0;
        len = 1;
        while (r < nums.size() - 1) {
            if (nums[r] > nums[r + 1]) {
                len++;
                maxLen = max(maxLen, len);
            } else {
                len = 1;
            }

            r++;
        }

        return maxLen;
    }
};