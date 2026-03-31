class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> prefixSum2Cnt;
        prefixSum2Cnt[0] = 1;
        int sum = 0, res = 0;
        for (auto n : nums) {
            sum += n;
            if (prefixSum2Cnt.count(sum - k)) {
                res += prefixSum2Cnt[sum - k];
            }

            prefixSum2Cnt[sum] ++;
        }

        return res;
    }
};