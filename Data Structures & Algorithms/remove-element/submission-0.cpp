class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res = 0;
        for (auto num : nums) {
            if (num != val) {
                res++;
            }
        }
        
        int k = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }

        return res;
    }
};