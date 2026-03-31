class Solution {
public:
    int maxProduct(vector<int>& nums) {
        auto res = *max_element(nums.begin(), nums.end());
        int curMax = 1, curMin = 1;
        for (auto n : nums) {
            auto tmp = curMax * n;
            curMax = max({curMax * n, curMin * n, n});
            curMin = min({tmp, curMin * n, n});
            res = max(res, curMax);
        }

        return res;
    }
};
