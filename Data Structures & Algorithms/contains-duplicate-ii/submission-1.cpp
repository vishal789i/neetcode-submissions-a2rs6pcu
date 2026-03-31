class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> num2Idx;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = num2Idx.find(nums[i]);
            if (it != num2Idx.end()) {
                if (abs(i - it->second) <= k) {
                    return true;
                }
                it->second = i;
            } else {
                num2Idx.emplace(nums[i], i);
            }
        }

        return false;
    }
};