class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int i = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i > 0 and nums[i - 1] == nums[i]) {
                continue;
            }

            for (int j = i + 1; j < n; ++j) {
                if (j > i + 1 and nums[j - 1] == nums[j]) {
                    continue;
                }

                int l = j + 1, r = n - 1;
                while (l < r) {
                    long long curSum = (long long)nums[i] + nums[j] + nums[l] + nums[r];
                    if (curSum == target) {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;

                        while (l < r and nums[l] == nums[l - 1]) {
                            l++;
                        }
                        
                        while (l < r and nums[r] == nums[r + 1]) {
                            r--;
                        }
                    } else if (curSum < target) {
                        l++;
                    } else {
                        r--;
                    }
                }
            }
        }

        return res;
    }
};