class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int preffix = 1;
        int suffix = 1;
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                preffix = suffix = 1;
            }

            preffix *= nums[i];
            suffix *= nums[nums.size() - i - 1];
            maxi = max(maxi, max(preffix, suffix));
        }

        return maxi;
    }
};
