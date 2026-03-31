class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num2Freq;
        for (auto num : nums) {
            num2Freq[num] ++;
        }

        vector<vector<int>> freq2Nums(nums.size() + 1);
        for (auto [num, freq] : num2Freq) {
            freq2Nums[freq].push_back(num);
        }

        vector<int> res;
        for (int i = freq2Nums.size() - 1; i >= 0; --i) {
            for (auto n : freq2Nums[i]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                }
            }
        }

        return res;
    }
};
