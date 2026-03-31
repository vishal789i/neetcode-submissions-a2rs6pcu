class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int l = 0, r = 0;
        k++;
        set<int> st;
        while (r < nums.size()) {
            if (r - l + 1 > k) {
                st.erase(nums[l]);
                l++;
            }

            if (st.count(nums[r])) {
                return true;
            }

            st.insert(nums[r]);
            r++;
        }

        return false;
    }
};