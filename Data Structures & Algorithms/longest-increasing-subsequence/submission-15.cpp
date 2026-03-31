class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 1);
        vector<int> hash(n);
        int lastIdx = 0;
        for (int i = 0; i < n; ++i) {
            hash[i] = i;
        }

        int res = 1;
        for (int idx = 0; idx < n; ++idx) {
            for (int prevIdx = 0; prevIdx < idx; ++prevIdx) {
                if (nums[prevIdx] < nums[idx] and dp[idx] < 1 + dp[prevIdx]) {
                    dp[idx] = 1 + dp[prevIdx];
                    hash[idx] = prevIdx;
                }
            }

            if (dp[idx] > res) {
                res = dp[idx];
                lastIdx = idx;
            }
        }

        vector<int> temp;
        temp.push_back(nums[lastIdx]);
        while (lastIdx != hash[lastIdx]) {
            lastIdx = hash[lastIdx];
            temp.push_back(nums[lastIdx]);
        }

        reverse(begin(temp), end(temp));

        for (int t : temp) {
            cout << t << '\t';
        }

        cout << endl;

        return res;
    }
};
