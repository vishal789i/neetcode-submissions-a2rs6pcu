class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> prefixSum2Cnt;
        prefixSum2Cnt[0] = 1;
        int sum = 0, res = 0;
        for (auto n : nums) {
            sum += n;
            auto it = prefixSum2Cnt.find(sum - k);
            if (it != prefixSum2Cnt.end()) {
                res += it->second;
            }

            prefixSum2Cnt[sum] ++;
        }

        return res;
    }
};