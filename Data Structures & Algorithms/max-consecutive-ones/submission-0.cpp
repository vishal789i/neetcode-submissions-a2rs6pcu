class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, res = 0;
        for (int n : nums) {
            if (n == 1) {
                count++;
                res = max(res, count);
            } else {
                count = 0;
            }
        }

        return res;
    }
};