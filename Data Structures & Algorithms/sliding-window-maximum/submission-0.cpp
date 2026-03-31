class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int currMax = INT_MIN;
        vector<int> res;
        
        int l = 0, r = k - 1;
        while (r < nums.size()) {
            int currMax = INT_MIN;
            for (int k = l; k <= r; k++) {
                currMax = max(currMax, nums[k]);
            }
            res.push_back(currMax);
            l++;
            r++;
        }

        return res;
    }
};
