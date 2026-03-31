class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> num2Idx;
        for (int i=0; i<nums.size(); ++i) {
            if (num2Idx.find(target-nums[i]) != num2Idx.end()) {
                return {num2Idx[target-nums[i]], i};
            }

            num2Idx[nums[i]] = i;
        }
        return {-1, -1};
    }
};
