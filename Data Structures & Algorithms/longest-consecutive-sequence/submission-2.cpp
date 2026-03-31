class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashSet;
        for (auto num : nums) hashSet.insert(num);

        int maxLen = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int len = 1;
            if (hashSet.find(nums[i] - 1) == hashSet.end()) {
                while (hashSet.find(nums[i] + len) != hashSet.end()) {
                    len += 1;
                }
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};
