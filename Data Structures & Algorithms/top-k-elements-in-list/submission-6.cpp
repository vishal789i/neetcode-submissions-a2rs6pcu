class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (auto num : nums) {
            mp[num]++;
        }

        vector<vector<int>> cnt2Nums(nums.size() + 1);
        for (auto it : mp) {
            cnt2Nums[it.second].push_back(it.first);
        }

        vector<int> res;
        for (auto i = cnt2Nums.size() - 1; i >= 0; i--) {
            for (auto num : cnt2Nums[i]) {
                res.push_back(num);
                k--;
                if (k == 0) return res;
            }
        }

        return res;
    }
};
