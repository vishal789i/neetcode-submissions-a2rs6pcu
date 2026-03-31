class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> sum2Cnt {{0, 1}};
        int sum = 0;
        int cnt = 0;
        for (auto num : nums) {
            sum += num;
            
            auto it = sum2Cnt.find(sum - k);
            if (it != sum2Cnt.end()) {
                cnt += it->second;
            }

            sum2Cnt[sum] += 1;
        }
        
        return cnt;
    }
};