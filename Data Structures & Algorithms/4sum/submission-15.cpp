class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        // [3,  2, 3, -3, 1, 0]
        // [-3, 0, 1,  2, 3, 3]
        //   i  j  l         r
        
        int i = 0;
        while (i < n - 3) {
            int j = i + 1;
            while (j < n - 2) {
                if (j > i + 1 and nums[j - 1] == nums[j]) {
                    continue;
                }

                int l = j + 1, r = n - 1;
                while (l < r) {
                    long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum < target) {
                        l++;
                    } else if (sum > target) {
                        r--;
                    } else {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                        while (l < r and nums[l - 1] == nums[l]) {
                            l++;
                        }

                        while (l < r and nums[r + 1] == nums[r]) {
                            r--;
                        }
                    }
                }

                j++;
                while (j < n - 2 and nums[j - 1] == nums[j]) {
                    j++;
                }
            }

            i++;
            while (i < n - 3 and nums[i - 1] == nums[i]) {
                i++;
            }
        }

        return res;
    }
};