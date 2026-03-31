class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> sum2Cnt {{0, 1}};
        int sum = 0;
        int cnt = 0;
        for (auto num : nums) {
            sum += num;
            if (sum2Cnt.find(sum - k) != sum2Cnt.end()) {
                cnt += sum2Cnt[sum - k];
            }

            sum2Cnt[sum] += 1;
        }
        return cnt;
    }
};