class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        while (i < n - 3) {
            int j = i + 1;
            while (j < n - 2) {
                int l = j + 1, r = n - 1;
                while (l < r) {
                    long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[l] + nums[r];
                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                        while (l < r and nums[l] == nums[l - 1]) {
                            l++;
                        }

                        while (l < r and nums[r] == nums[r + 1]) {
                            r--;
                        }
                    } else if (sum > target) {
                        r--;
                    } else {
                        l++;
                    }
                }

                j++;
                while (j < n - 2 and nums[j] == nums[j - 1]) {
                    j++;
                }
            }

            i++;
            while (i < n - 3 and nums[i] == nums[i - 1]) {
                i++;
            }
        }

        return res;
    }
};