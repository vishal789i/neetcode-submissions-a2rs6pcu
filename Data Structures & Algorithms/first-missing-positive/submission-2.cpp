class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<bool> seen(nums.size());

        for (auto num : nums) {
            if (num - 1 >= 0 and num - 1 < nums.size())
                seen[num - 1] = true;
        }

        for (int i = 0; i < seen.size(); ++i) {
            if (not seen[i]) {
                return i + 1;
            }
        }

        return seen.size() + 1; 
    }
};