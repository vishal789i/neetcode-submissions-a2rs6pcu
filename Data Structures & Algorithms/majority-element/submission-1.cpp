class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int res = 0;
        for (auto num : nums) {
            if (count == 0) {
                res = num;
            }

            if (res == num) {
                count ++;
            } else {
                count --;
            }
        }

        return res;
    }
};