class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = mp.find(target - nums[i]);
            if (it != mp.end()) {
                std::set<int> s({it->second, i});
                return std::vector<int>(s.begin(), s.end());
            }

            mp.insert({nums[i], i});
        }

        return {-1, -1};
    }
};
