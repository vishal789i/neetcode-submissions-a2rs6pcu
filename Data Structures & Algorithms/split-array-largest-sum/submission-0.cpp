class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end()), r = accumulate(nums.begin(), nums.end(), 0);
        int res = l;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int curSum = 0;
            int parts = 0;
            for (auto n : nums) {
                if (curSum + n > m) {
                    curSum = n;
                    parts++;
                } else {
                    curSum += n;
                }
            }

            if (parts < k) {
                res = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return res;
    }
};