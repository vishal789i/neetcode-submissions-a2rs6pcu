class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> num2Freq;
        for (auto num: nums) {
            num2Freq[num]++;
        }
        
        std::vector<std::vector<int>> freq2NumsVec(nums.size() + 1);
        for (auto& entry: num2Freq) {
            freq2NumsVec[entry.second].push_back(entry.first);
        }

        std::vector<int> ans;
        for (int i=freq2NumsVec.size()-1; i>0; --i) {
            for (auto num: freq2NumsVec[i]) {
                ans.push_back(num);
                if (ans.size() == k) {
                    return ans;
                }
            }
        }
        return ans;
    }
};
