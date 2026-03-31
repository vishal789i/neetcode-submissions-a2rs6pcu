class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n + 1, 1), hash(n);
        for (int i = 0; i < n; ++i) {
            hash[i] = i;
        }
        
        int lastIdx = 0, res = 1;
        for (int i = 0; i < n; ++i) {
            for (int prev = 0; prev < i; ++prev) {
                if (nums[i] % nums[prev] == 0 and dp[prev] + 1 > dp[i]) {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }

            if (dp[i] > res) {
                res = dp[i];
                lastIdx = i;
            }
        }

        vector<int> temp;
        temp.push_back(nums[lastIdx]);
        while (lastIdx != hash[lastIdx]) {
            lastIdx = hash[lastIdx];
            temp.push_back(nums[lastIdx]);
        }

        return temp;
    }
};