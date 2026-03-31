class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int i=0, longest = 0;
        unordered_set<int> numSet(nums.begin(), nums.end());
        while (i < nums.size()) {
            if (numSet.count(nums[i] - 1) == 0) {
                int currLength = 1;
                while (numSet.count(nums[i] + currLength) != 0) {
                    currLength += 1;
                }
                longest = max(longest, currLength);
            }
            i++;
        }
        return longest;
    }
};
