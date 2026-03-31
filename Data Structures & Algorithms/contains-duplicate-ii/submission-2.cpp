class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> window;
        int l = 0, r = 0;
        while (r < nums.size()) {
            while (r - l > k) {
                window.erase(nums[l]);
                l++;
            }

            if (window.count(nums[r])) {
                return true;
            }

            window.insert(nums[r]);
            r++;
        }

        return false;
    }
};