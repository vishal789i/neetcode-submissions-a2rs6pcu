class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        for (int i = 0; i <= r; ++i) {   // WARN: move i till r not n!
            if (nums[i] == 0) {
                swap(nums[l], nums[i]); // move to start
                l++;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[r]); // move to end
                r--;
                i--; // dont move i
            }
        }
    }
};