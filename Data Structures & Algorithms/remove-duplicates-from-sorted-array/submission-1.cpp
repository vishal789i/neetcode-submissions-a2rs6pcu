class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0, r = 0;
        while (r < nums.size()) {
            nums[l] = nums[r];
            while (r < nums.size() and nums[l] == nums[r]) {
                r++;
            }
            l++;
        }
        return l;
    }
};